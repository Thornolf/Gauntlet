/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
// Last update Thu Jun 15 14:43:56 2017 Thomas Fossaert
*/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

#include "GameCore.hpp"

GameCore::GameCore() {}

GameCore::~GameCore() {}

void GameCore::createScene()
{
  map = new MapManager("dist/bin/map.cfg");
  map->computeAbstractTree();
  map->generateMap(*this->mRenderManager);
  this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->setOgreBase(this->mSceneMgr);});

  mPosition = new Position(100, 0, -450);
  mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));

  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().createPlane("ground",
						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
						plane, 10000, 10000, 1, 1, true, 1, 40, 40,
						Ogre::Vector3::UNIT_Z);
  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
  groundEntity->setMaterialName("Examples/Rockwall");

  collision = new CollisionTools();
  this->mRenderManager->forEachEntity([&](GameObject* gObj){collision->register_entity(gObj->getEntity(), Collision::COLLISION_BOX);});
  this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->initScript(collision);});
}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseGauntlet::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;
  /*mAnimationState->addTime(fe.timeSinceLastFrame);*/
  return ret;
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  Ogre::Vector3		dirVec = Ogre::Vector3::ZERO;
  Ogre::Vector3		CameraVec = Ogre::Vector3::ZERO;

  mConfig->forEachPlayer([&](Pc *player){player->Animate(fe);});

  mConfig->forEachPlayer([&](Pc *player) {
    SCheckCollisionAnswer	collider = collision->check_ray_collision(player->getSceneNode()->getPosition(),
									   player->getSceneNode()->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 100.0f, 100.0f, 1,
									   player->getEntity(),
									   false);
    if (collider.collided)
    {
      dirVec.x -= 20 + player->getSpeed();
      if (!collider.entity->getName().compare(0,9, "goldStack"))
      {
	collision->remove_entity(collider.entity);
	mSceneMgr->destroyEntity(collider.entity);
	// static_cast<Character*>(warrior)->setScore(100);
      }
      else if (!collider.entity->getName().compare(0,9, "foodStack"))
      {
	collision->remove_entity(collider.entity);
	mSceneMgr->destroyEntity(collider.entity);
	// static_cast<Character*>(warrior)->gainHealth(50);
      }
    }
  });

  for (auto itBinding = this->mKeyboardBinding.begin(); itBinding != this->mKeyboardBinding.end(); ++itBinding)
  {
    OIS::KeyCode	key	= itBinding->first;
    Pc			*player	= itBinding->second.first;
    eventType		event	= itBinding->second.second;

    if (mKeyboard->isKeyDown(key))
    {
      for (auto itEvent = player->_event.begin(); itEvent != player->_event.end(); ++itEvent)
      {
	if (itEvent->first == event)
	{
	  itEvent->second(fe, dirVec, CameraVec);
	  this->mCamera->move(CameraVec);
	  player->getSceneNode()->translate(dirVec * fe.timeSinceLastFrame,Ogre::Node::TS_LOCAL);
	  return (true);
	}
      }
    }
  }
  /* FOCUS DU TANK*/
  // this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->launchScript(mSceneMgr, *this->mConfig->getPlayers().begin(), fe);});
  /* FOCUS DU TANK*/
  return true;
}
