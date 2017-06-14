/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
** Last update Tue Jun 13 21:00:51 2017 Robin Grattepanche
*/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

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
  GameObject		*mZob = new Zombie(100, 0, 100, 100);
  GameObject		*mTank = new Tank("noob", 500, 0, 500);

  //GameObject		*mZob2 = new Zombie(-100, 0, -100, 1);

  Ogre::Entity		*ent;
  Ogre::Entity		*wall;
  Ogre::SceneNode	*node;

  map = new MapManager("dist/bin/map.cfg");
  map->computeAbstractTree();
  map->generateMap(render);
  render.forEachEntity([&](GameObject* gObj){gObj->setOgreBase(this->mSceneMgr);});

  mPosition = new Position(100, 0, -750);
  //mEntity = mSceneMgr->createEntity("Ninja", "ninja.mesh");
   mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
  //light *ambient = new light(mSceneMgr, "ambient", Ogre::Light::LT_DIRECTIONAL, 0, 50, 0);
  //ambient->setDiffuseColour(Ogre::ColourValue(1.0, 1.0, 1.0));
  mEntity = mSceneMgr->createEntity("Ninja", "character_human_female_humanfemale_hd.mesh");

  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_sword_2h_artifactashbringer_d_01.mesh");
  this->mEntity->attachObjectToBone("character/human/female/humanfemale_hd_bone_117", weapon, Ogre::Quaternion(1,1,0,0));

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NinjaNode", Ogre::Vector3(100.0f, 0.0f, 25.0f));
  mNode->attachObject(mEntity);
  mNode->setScale(2,2,2);
  mTank->setOgreBase(mSceneMgr);
  Skeleton *mSkull = new Skeleton(200, 0, 200, 50);

  //mNode->attachObject(mCamera);
  wall = mSceneMgr->createEntity("Cube", "cube.mesh");
  node = mSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode", Ogre::Vector3(0.0f, 50.0f,  750.0f));
  node->attachObject(wall);
  wall->setMaterialName("Examples/Rocky");
  node->setScale(15.0f, 7.0f, 0.3f);

  mNode->setOrientation(1,0,0,0);
//  mNode->setScale(2,2,2);


  mZombieEnt = mSceneMgr->createEntity("Robot", "creature_northrendghoul2_northrendghoul2.mesh");
  mZombie = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode", mPosition->getVector());
  mZombie->attachObject(mZombieEnt);
  mZombie->setScale(1.5f, 1.5f, 1.5f);
  mZombie->setOrientation(1,1,0,0);


  mSkull->setOgreBase(mSceneMgr);

  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().createPlane("ground",
						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
						plane, 10000, 1500, 1, 1, true, 1, 40, 5,
						Ogre::Vector3::UNIT_Z);
  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
  groundEntity->setMaterialName("Examples/Rockwall");

  Script *mScript = new Script();

  collision = new CollisionTools();
  //collision->register_entity(mEntity, Collision::COLLISION_BOX);
  //collision->register_entity(wall, Collision::COLLISION_BOX);
  //collision->register_entity(mZombieEnt, Collision::COLLISION_BOX);
  render.forEachEntity([&](GameObject* gObj){collision->register_entity(gObj->getEntity(), Collision::COLLISION_BOX);});
}

void GameCore::createFrameListener(void)
{
  BaseGauntlet::createFrameListener();
  mAnimationState = mEntity->getAnimationState("Walk");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);

  /*mAnimationStateZombie = mZombieEnt->getAnimationState("Stand");
  mAnimationStateZombie->setLoop(true);
  mAnimationStateZombie->setEnabled(true);*/
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
  static Ogre::Real rotate = .05;
  static Ogre::Real move = 150;

  // bool leftMouseDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);

  // if (leftMouseDown)
    // mAnimationState = _animation->simpleAnimation(mAnimationState, "Special", fe, mEntity);

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
    dirVec.x -= 2 + move;
  if (mKeyboard->isKeyDown(OIS::KC_L))
  {
    mNode->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
    dirVec.x += move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_M))
  {
    mNode->setOrientation(Ogre::Quaternion(0, 0, 1, 0));
    dirVec.x += move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_K))
  {
    mNode->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
    dirVec.x += move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

  else if (mKeyboard->isKeyDown(OIS::KC_O))
  {
    mNode->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
    dirVec.x += move;
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  }

	if (mKeyboard->isKeyDown(OIS::KC_J))
	{
		mSceneMgr->getSceneNode("NinjaNode")->yaw(Ogre::Radian(rotate),
			Ogre::Node::TS_LOCAL);
		std::cout << mSceneMgr->getSceneNode("NinjaNode")->getOrientation() << std::endl;
	}

  mSceneMgr->getSceneNode("NinjaNode")->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);

  // mSceneMgr->getSceneNode("RobotNode")->translate(
    // mScript->ZombieScript(mZombie, mNode) * fe.timeSinceLastFrame,
    // Ogre::Node::TS_LOCAL);

  /*mSceneMgr->getSceneNode("ZombieNode100")->translate(
  mZob->launchScript(mSceneMgr, mNode) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);*/

  mAnimationState = _animation->loopAnimation(mAnimationState, "Stand", fe, mEntity);

  render.forEachEntity([&](GameObject* gObj){gObj->launchScript(mSceneMgr, mNode, fe);});
  // render.forEachEntity([&](GameObject* gObj){gObj->Animate(fe);});

  mAnimationStateZombie = mZombieEnt->getAnimationState("Stand");
  mAnimationStateZombie->setLoop(true);
  mAnimationStateZombie->setEnabled(true);
  return true;
  /*if (mKeyboard->isKeyDown(OIS::KC_J))
  {
    Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
    mNode->yaw(Ogre::Degree(0.25));
  }
  if (mKeyboard->isKeyDown(OIS::KC_H))
  {
    Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
    mNode->yaw(Ogre::Degree(-0.25));
  }*/
}
