/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
// Last update Fri Jun  9 11:33:21 2017 Thomas Fossaert
*/

#include "GameCore.hpp"
#include "Position.hpp"
#include	"Light/light.hpp"
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
  GameObject		*mZob = new Zombie(100, 0, 100, 1);
  //GameObject		*mZob2 = new Zombie(-100, 0, -100, 1);

  Ogre::Entity		*ent;
  Ogre::Entity		*wall;
  Ogre::SceneNode	*node;

  MapManager *map = new MapManager("dist/bin/map.cfg");
  RenderManager render;;
  //map->loadFromFile();
  map->computeAbstractTree();
  map->generateMap(render);

  mPosition = new Position(100, 0, -750);
  //mEntity = mSceneMgr->createEntity("Ninja", "ninja.mesh");
  // mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
  light *ambient = new light(mSceneMgr, "ambient", Ogre::Light::LT_DIRECTIONAL, 0, 0, 0);
  ambient->setDiffuseColour(Ogre::ColourValue(1.0, 1.0, 1.0));
  mEntity = mSceneMgr->createEntity("Ninja", "ninja.mesh");

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NinjaNode", Ogre::Vector3(100.0f, 0.0f, 25.0f));
  mNode->attachObject(mEntity);

  Skeleton *mSkull = new Skeleton(200, 0, 200, 1);

  //_entityVector.push_back(mZob);

  //mNode->attachObject(mCamera);
  wall = mSceneMgr->createEntity("Cube", "cube.mesh");
  node = mSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode", Ogre::Vector3(0.0f, 50.0f,  750.0f));
  node->attachObject(wall);
  wall->setMaterialName("Examples/Rocky");
  node->setScale(15.0f, 7.0f, 0.3f);

  ent = mSceneMgr->createEntity("Ogre", "creature_fellord_fellord.mesh");
  node = mSceneMgr->getRootSceneNode()->createChildSceneNode("OgreMesh", Ogre::Vector3(0.0f, 100.0f, 0.0f));
  node->attachObject(ent);
  node->setScale(1.0f, 1.0f, 1.0f);
  node->setOrientation(1,1,0,0);

  //mNode->setOrientation(1,1,0,0);
//  mNode->setScale(2,2,2);

  mZombieEnt = mSceneMgr->createEntity("Robot", "creature_northrendghoul2_northrendghoul2.mesh");
  mZombie = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode", mPosition->getVector());
  mZombie->attachObject(mZombieEnt);
  mZombie->setScale(1.5f, 1.5f, 1.5f);
  mZombie->setOrientation(1,1,0,0);


  mSkull->setOgreBase(mSceneMgr);
  for (auto &it : _entityVector)
  {
    it->setOgreBase(mSceneMgr);
  }

  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().createPlane("ground",
						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
						plane, 15000, 15000, 150, 150, true, 1, 20, 20,
						Ogre::Vector3::UNIT_Z);
  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
  groundEntity->setMaterialName("Examples/Rockwall");

  Script *mScript = new Script();

  collision = new CollisionTools();
  collision->register_entity(mEntity, Collision::COLLISION_BOX);
  collision->register_entity(wall, Collision::COLLISION_BOX);
  //collision->register_entity(ent, Collision::COLLISION_BOX);
  collision->register_entity(mZombieEnt, Collision::COLLISION_BOX);

}

void GameCore::createFrameListener(void)
{
  BaseGauntlet::createFrameListener();
  mAnimationState = mEntity->getAnimationState("Idle1");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);

  mAnimationStateZombie = mZombieEnt->getAnimationState("Run");
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
    mAnimationState = _animation->loopAnimation(mAnimationState, "Attack1", fe, mEntity);
    if (_entityVector.empty() != true)
    {
      _entityVector.back()->unsetEntity(mSceneMgr);
      _entityVector.pop_back();
    }
  }

  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  SCheckCollisionAnswer collider = collision->check_ray_collision(mSceneMgr->getSceneNode("NinjaNode")->getPosition(),
								  mSceneMgr->getSceneNode("NinjaNode")->getPosition() + Ogre::Vector3(50.0f, 50.0f, 50.0f), 50.0f, 50.0f, 1,
								  mEntity,
								  false);


  SCheckCollisionAnswer Zcollider = collision->check_ray_collision(mSceneMgr->getSceneNode("RobotNode")->getPosition(),
                			           mSceneMgr->getSceneNode("RobotNode")->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 70.0f, 70.0f, 1,
                								  mEntity,
                								  false);
  if (collider.collided)
    dirVec.z += 2 + move;
  if (mKeyboard->isKeyDown(OIS::KC_L))
  {
    mNode->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
    dirVec.z -= move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_M))
  {
    mNode->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
    dirVec.z -= move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_K))
  {
    mNode->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
    dirVec.z -= move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  else if (mKeyboard->isKeyDown(OIS::KC_O))
  {
    mNode->setOrientation(Ogre::Quaternion(0, 0, -1, 0));
    dirVec.z -= move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  mSceneMgr->getSceneNode("NinjaNode")->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);

  if (Zcollider.collided)
  {
    mSceneMgr->getSceneNode("RobotNode")->translate(
      mScript->ZombieScript(mZombie, mNode) * fe.timeSinceLastFrame,
      Ogre::Node::TS_LOCAL);
  }

  /*mSceneMgr->getSceneNode("ZombieNode1")->translate(
  mZob->launchScript(mSceneMgr, mNode) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);*/

  mAnimationState = _animation->loopAnimation(mAnimationState, "Idle1", fe, mEntity);

  mAnimationStateZombie = mZombieEnt->getAnimationState("Run");
  mAnimationStateZombie->setLoop(true);
  mAnimationStateZombie->setEnabled(true);
  return true;
  if (mKeyboard->isKeyDown(OIS::KC_J))
  {
    Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
    mNode->yaw(Ogre::Degree(0.25));
  }
  if (mKeyboard->isKeyDown(OIS::KC_H))
  {
    Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
    mNode->yaw(Ogre::Degree(-0.25));
  }
}
