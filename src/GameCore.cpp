/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
// Last update Fri May 26 10:57:04 2017 Thomas Fossaert
*/

#include "GameCore.hpp"
#include "Position.hpp"
#include "audio/Music.hpp"
#include "GameObject/Character/Pc/Pc.hpp"

GameCore::GameCore()
{
}

GameCore::~GameCore()
{
}

void GameCore::createScene()
{
    Zombie *mZob = new Zombie(100, 0, 100);
    Position *mPosition = new Position(100, 0, -750);
     mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
     mEntity = mSceneMgr->createEntity("Ninja", "ninja.mesh");

     mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NinjaNode", Ogre::Vector3(0.0f, 0.0f, 25.0f));
     mNode->attachObject(mEntity);

     Ogre::Entity *ent;
     Ogre::Entity *wall;
     Ogre::SceneNode *node;
      //mCamera->lookAt(Ogre::Vector3(200.0f, 0.0f, 25.0f));
     mNode->attachObject(mCamera);
     wall = mSceneMgr->createEntity("Cube", "cube.mesh");
     node = mSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode", Ogre::Vector3(0.0f, 50.0f,  750.0f));
     node->attachObject(wall);
     wall->setMaterialName("Examples/Rocky");
     node->setScale(15.0f, 7.0f, 0.3f);

     mZombieEnt = mSceneMgr->createEntity("Robot", "robot.mesh");
     mZombie = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode", mPosition->getVector());
     mZombie->attachObject(mZombieEnt);
     mZombie->setScale(3.0f, 3.0f, 3.0f);

     mZob->setOgreBase(mSceneMgr);

     Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
     Ogre::MeshManager::getSingleton().createPlane("ground",
     Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
     plane, 1500, 1500, 20, 20, true, 1, 20, 20,
     Ogre::Vector3::UNIT_Z);
     Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
     mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
     groundEntity->setMaterialName("Examples/Rockwall");


     CollisionTools *collision = new CollisionTools();
     collision->register_entity(mEntity, COLLISION_ACCURATE);
     collision->register_entity(wall, COLLISION_ACCURATE);
     collision->register_entity(mZombieEnt, COLLISION_ACCURATE);

     Script *mScript = new Script();
}

void GameCore::createFrameListener(void)
{
  BaseGauntlet::createFrameListener();
  mAnimationState = mEntity->getAnimationState("Idle1");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);

  mAnimationStateZombie = mZombieEnt->getAnimationState("Walk");
  mAnimationStateZombie->setLoop(true);
  mAnimationStateZombie->setEnabled(true);
}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseGauntlet::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;
  mAnimationState->addTime(fe.timeSinceLastFrame);
  mAnimationStateZombie->addTime(fe.timeSinceLastFrame);
  return ret;
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  static bool mouseDownLastFrame = false;
  static Ogre::Real toggleTimer = 0.0;
  static Ogre::Real rotate = .13;
  static Ogre::Real move = 150;

  bool leftMouseDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);

  if (leftMouseDown)
  {
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Attack2", fe, mEntity);
  }

  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  //SCheckCollisionAnswer collider = collision->check_ray_collision(Ogre::Ray(mNode->getPosition(), Ogre::Vector3(100.0f, 0.0f,  100.0f)), Ogre::SceneManager::ENTITY_TYPE_MASK, nullptr, 100, true);
  SCheckCollisionAnswer ret = collision->check_ray_collision(mNode->getPosition(), mNode->getPosition() + Ogre::Vector3(0.0f, 0.0f,  -750.0f), 1.0f, 1.0f, Ogre::SceneManager::ENTITY_TYPE_MASK, mEntity, false);
  if (ret.collided)
  {
    dirVec.y += 500;
  }

  if (mKeyboard->isKeyDown(OIS::KC_K))
  {
    dirVec.x -= move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  if (mKeyboard->isKeyDown(OIS::KC_M))
  {
    dirVec.x += move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  if (mKeyboard->isKeyDown(OIS::KC_O))
  {
    dirVec.z += move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  if (mKeyboard->isKeyDown(OIS::KC_L))
  {
    dirVec.z -= move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  mSceneMgr->getSceneNode("NinjaNode")->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);

  mSceneMgr->getSceneNode("RobotNode")->translate(
    mScript->ZombieScript(mZombie, mNode) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);

  /*mSceneMgr->getSceneNode("ZombieNode")->translate(
  mZob->launchScript(mNode) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);*/

  mAnimationState = _animation->loopAnimation(mAnimationState, fe, mEntity);

  mAnimationStateZombie = mZombieEnt->getAnimationState("Walk");
  mAnimationStateZombie->setLoop(true);
  mAnimationStateZombie->setEnabled(true);
  return true;
}
