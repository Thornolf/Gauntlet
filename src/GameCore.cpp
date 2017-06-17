/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
** Last update Fri Jun 16 13:48:50 2017 Robin Grattepanche
*/

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Audio.hpp>

#include "GameCore.hpp"

GameCore::GameCore() {}

GameCore::~GameCore() {}

void GameCore::createScene()
{
  /* ----------------------------START SET MUSIC ---------------------------*/
  Music *backgroundMusic = new Music("dist/media/musicgame/AmbianceDeadMine.ogg", "AmbientDeadmine");

  backgroundMusic->playAudio();
  backgroundMusic->setLoop(true);
  backgroundMusic->setAudioVolume(10.0);
  _mmusic.insert(std::make_pair("Waluni1", new Music("dist/media/musicgame/KarazhanMusic/KarazhanGeneralWaluni1.ogg", "Waluni1")));
  _mmusic.insert(std::make_pair("Waluni2", new Music("dist/media/musicgame/KarazhanMusic/KarazhanGeneralWaluni2.ogg", "Waluni2")));
  _mmusic.insert(std::make_pair("Waluni3", new Music("dist/media/musicgame/KarazhanMusic/KarazhanGeneralWaluni3.ogg", "Waluni3")));
  _mmusic.insert(std::make_pair("Plague", new Music("dist/media/musicgame/NaxxRamas/Naxxramas_1_Plague.ogg", "Plague")));
  _mmusic.insert(std::make_pair("Kelthusad", new Music("dist/media/musicgame/NaxxRamas/Naxxramas_2_Kelthusad.ogg", "Kelthusad")));
  _mmusic.insert(std::make_pair("Abomination", new Music("dist/media/musicgame/NaxxRamas/Naxxramas_3_Abomination.ogg", "Abomination")));
  _mmusic.insert(std::make_pair("Wyrm", new Music("dist/media/musicgame/NaxxRamas/Naxxramas_4_Wyrm.ogg", "Wyrm")));
  _msound.insert(std::make_pair("gold", new Sound("dist/media/soundeffect/PowerUpSound/GoldSound.ogg", "gold")));
  _msound.insert(std::make_pair("food", new Sound("dist/media/soundeffect/PowerUpSound/FoodSound.ogg", "food")));
  _msound.insert(std::make_pair("key", new Sound("dist/media/soundeffect/PowerUpSound/KeySound.ogg", "key")));
  auto itm = _mmusic.begin();
  itm->second->playAudio();
  this->setCurrMusicName(itm->second->getCurrentName());
  /* ----------------------------END SET MUSIC ---------------------------*/

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
  bool		ret = BaseGauntlet::frameRenderingQueued(fe);
  auto		it = _mmusic.find(this->_currentMusic);

  mKeyboard->capture();
  mMouse->capture();
  if (!processUnbufferedInput(fe))
    return false;
  /* START MUSIC */
  if (_mmusic[this->_currentMusic]->getStatus() ==  sf::SoundSource::Status::Stopped)
  {
    if (it == _mmusic.end())
      throw IndieException("Music can't be load");
    if (++it == _mmusic.end())
      it = _mmusic.begin();
    this->setCurrMusicName(it->second->getCurrentName());
    it->second->playAudio();
  }
  /* END MUSIC */
  /*mAnimationState->addTime(fe.timeSinceLastFrame);*/
  return ret;
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  Ogre::Vector3			dirVec = Ogre::Vector3::ZERO;
  Ogre::Vector3			CameraVec = Ogre::Vector3::ZERO;
  GameObject			*tmp;
  std::stack<std::thread *>	threadPool;

  mConfig->forEachPlayer([&](Pc *player){player->Animate(fe);});

  this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->launchScript(mSceneMgr, *this->mConfig->getPlayers().begin(), fe);});
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
	  SCheckCollisionAnswer	collider = collision->check_ray_collision(player->getSceneNode()->getPosition(),
										 player->getSceneNode()->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 100.0f, 100.0f, 1,
										 player->getEntity(),
										 false);

	  if (collider.collided)
	  {
	    dirVec.x -= 20 + player->getSpeed();
	    if (!collider.entity->getName().compare(0,9, "goldStack"))
	    {
	      if ((tmp = this->mRenderManager->searchEntities(collider.entity->getName())))
	      {
		tmp->unsetEntity(mSceneMgr);
		mConfig->addScorePoint(100);
		_msound["gold"]->playAudio();
		this->mRenderManager->eraseEntities(tmp);
		collision->remove_entity(collider.entity);
	      }
	    }
	    else if (!collider.entity->getName().compare(0,9, "foodStack"))
	    {
	      if ((tmp = this->mRenderManager->searchEntities(collider.entity->getName())))
	      {
		tmp->unsetEntity(mSceneMgr);
		player->gainHealth(50);
		_msound["food"]->playAudio();
		//static_cast<Character*>(warrior)->gainHealth(50); /!\ Régler le segfault
		this->mRenderManager->eraseEntities(tmp);
		collision->remove_entity(collider.entity);
	      }
	    }
	    else if (!collider.entity->getName().compare(0,3, "key"))
	    {
	      if ((tmp = this->mRenderManager->searchEntities(collider.entity->getName())))
	      {
		tmp->unsetEntity(mSceneMgr);
		_msound["key"]->playAudio();
		/* Action to set the possession of the key */
		this->mRenderManager->eraseEntities(tmp);
		collision->remove_entity(collider.entity);
	      }
	    }
	  }
	  else
	  {
	    //std::thread *animThread = new std::thread([&]{
	      itEvent->second(fe, dirVec, CameraVec, collision, mSceneMgr);
	      this->mCamera->move(CameraVec);
	    //});
	   // threadPool.push(animThread);
	  }
	  player->getSceneNode()->translate(dirVec * fe.timeSinceLastFrame,Ogre::Node::TS_LOCAL);
	  return (true);
	}
      }
    }
  }
  /*
  for (;threadPool.size() > 0;)
  {
    threadPool.top()->join();
    delete threadPool.top();
    threadPool.pop();
  }
   */
  return true;
}

void		GameCore::setCurrMusicName(std::string newCurrName)
{
  this->_currentMusic = newCurrName;
}

std::string	GameCore::getCurrMusicName() const
{
  return (this->_currentMusic);
}
