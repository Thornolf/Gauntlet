/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
// Last update Thu Jun 15 10:16:47 2017 Thomas Fossaert
*/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

#include "GameCore.hpp"

GameCore::GameCore()
{
  /* Configuration initialisation */
  /*Configuration		*mConfig = new Configuration();
  std::vector<Pc*>	players;
  Pc			*unitPlayer;

  unitPlayer = static_cast<Pc*>(_render.createGameObject("TANK", Position(500, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  players.push_back(unitPlayer);
  unitPlayer = static_cast<Pc*>(_render.createGameObject("MAGE", Position(200, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  players.push_back(unitPlayer);
  unitPlayer = static_cast<Pc*>(_render.createGameObject("ARCHER", Position(-100, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  players.push_back(unitPlayer);
  unitPlayer = static_cast<Pc*>(_render.createGameObject("WARRIOR", Position(-400, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
     players.push_back(unitPlayer);
  mConfig->setPlayers(players);*/
  /* Configuration END initialisation */
}

GameCore::~GameCore()
{
}

void GameCore::createScene()
{
  warrior = new Warrior("Warrrrrior", 100, 0, 25);

  map = new MapManager("dist/bin/map.cfg");
  map->computeAbstractTree();
  map->generateMap(_render);
  this->_render.forEachEntity([&](GameObject* gObj){gObj->setOgreBase(this->mSceneMgr);});

  mPosition = new Position(100, 0, -450);
   mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
  warrior->setOgreBase(mSceneMgr);

  //mNode->attachObject(mCamera);

  mZombieEnt = mSceneMgr->createEntity("Robot", "creature_northrendghoul2_northrendghoul2.mesh");
  mZombie = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode", mPosition->getVector());
  mZombie->attachObject(mZombieEnt);
  mZombie->setScale(1.5f, 1.5f, 1.5f);

  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().createPlane("ground",
						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
						plane, 10000, 1500, 1, 1, true, 1, 40, 5,
						Ogre::Vector3::UNIT_Z);
  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
  groundEntity->setMaterialName("Examples/Rockwall");

  collision = new CollisionTools();
  this->_render.forEachEntity([&](GameObject* gObj){collision->register_entity(gObj->getEntity(), Collision::COLLISION_BOX);});
  this->_render.forEachEntity([&](GameObject* gObj){gObj->initScript(collision);});
}

void GameCore::createFrameListener(void)
{
  BaseGauntlet::createFrameListener();
  /*mAnimationState = mEntity->getAnimationState("Run");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);*/
}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseGauntlet::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;
  /*mAnimationState->addTime(fe.timeSinceLastFrame);*/
    mAnimationStateZombie->addTime(fe.timeSinceLastFrame);
  return ret;
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  static bool		mouseDownLastFrame = false;
  static Ogre::Real	toggleTimer = 0.0;
  static Ogre::Real	rotate = .05;
  static Ogre::Real	move = 350;

  if (mMouse->getMouseState().buttonDown(OIS::MB_Left))
    mAnimationState = _animation->simpleAnimation(mAnimationState, "Death", fe, mEntity);

  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
  SCheckCollisionAnswer	collider = collision->check_ray_collision(mSceneMgr->getSceneNode("WarriorNode")->getPosition(),
								  mSceneMgr->getSceneNode("WarriorNode")->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 100.0f, 100.0f, 1,
								  mEntity,
								  false);

  SCheckCollisionAnswer Zcollider = collision->check_ray_collision(mSceneMgr->getSceneNode("RobotNode")->getPosition(),
                			           mSceneMgr->getSceneNode("RobotNode")->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 70.0f, 70.0f, 1,
                								  mZombieEnt,
                								  false);

  this->_config.forEachPlayer([&](Pc *player){player->Animate(fe);});

  if (collider.collided)
    dirVec.x -= 20 + move;
  else
  {
  if (mKeyboard->isKeyDown(OIS::KC_L))
  {
    warrior->getSceneNode()->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
    dirVec.x += move;
    warrior->Animate(fe);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_M))
  {
    warrior->getSceneNode()->setOrientation(Ogre::Quaternion(0, 0, 1, 0));
    dirVec.x += move;
    warrior->Animate(fe);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_K))
  {
    warrior->getSceneNode()->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
    dirVec.x += move;
    warrior->Animate(fe);
  }
  else if (mKeyboard->isKeyDown(OIS::KC_O))
  {
    warrior->getSceneNode()->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
    dirVec.x += move;
    warrior->Animate(fe);
  }
  /*else if (mKeyboard->isKeyDown(OIS::KC_I))
  {
    warrior->launchAnimation(fe, ATTACK);
    warrior->mAnimationState = warrior->mAnimation->getAnimationState();
  }*/
 }
  warrior->getSceneNode()->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);


  this->_render.forEachEntity([&](GameObject* gObj){gObj->launchScript(mSceneMgr, warrior, fe);});
  // render.forEachEntity([&](GameObject* gObj){gObj->Animate(fe);});

  mAnimationStateZombie = mZombieEnt->getAnimationState("Stand");
  mAnimationStateZombie->setLoop(true);
  mAnimationStateZombie->setEnabled(true);
  return true;
}
