/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
// Last update Sat Jun 17 23:28:45 2017 Thomas Fossaert
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <OgreFontManager.h>

#include "GameCore.hpp"

GameCore::GameCore()
{
  this->_lootEvent["gol"]	= std::bind(&GameCore::takeGoldStack, this, std::placeholders::_1, std::placeholders::_2);
  this->_lootEvent["foo"]	= std::bind(&GameCore::takeFoodStack, this, std::placeholders::_1, std::placeholders::_2);
  this->_lootEvent["key"]	= std::bind(&GameCore::takeKey, this, std::placeholders::_1, std::placeholders::_2);
  this->_lootEvent["Gat"]	= std::bind(&GameCore::takeGate, this, std::placeholders::_1, std::placeholders::_2);
}

GameCore::~GameCore() {}

void GameCore::createScene()
{
  this->_hud = new HUD("HUDpanel");

  this->_hud->setupPanel(400, 880, 1120, 186, "Examples/OverlayBottom");
  this->_hud->setupPanelKey(1519, 880, 135, 135, "Examples/KeyDown");
  this->_hud->initTextPlayer();
  this->_hud->createPlayers();
  mConfig->forEachPlayer([&](Pc *player){this->_hud->getPlayerHp(player->getHp());});
  this->_hud->initLife();
  this->_hud->initScore(530, 30, Ogre::ColourValue(0.1, 0.1, 0.1));
  Music *backgroundMusic = new Music("dist/media/musicgame/AmbianceDeadMine.ogg", "AmbientDeadmine");

  backgroundMusic->setAudioVolume(10.0);
  backgroundMusic->playAudio();
  backgroundMusic->setLoop(true);
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
  itm->second->setAudioVolume(5);
  itm->second->playAudio();
  this->setCurrMusicName(itm->second->getCurrentName());

  map = new MapManager("dist/bin/map.cfg");
  map->computeAbstractTree();
  map->generateMap(*this->mRenderManager);
  this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->setOgreBase(this->mSceneMgr);});

  mPosition = new Position(100, 0, -450);
  mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));

  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
  Ogre::MeshManager::getSingleton().createPlane("ground",
						Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
						plane, 20000, 20000, 1, 1, true, 1, 40, 40,
						Ogre::Vector3::UNIT_Z);
  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
  groundEntity->setMaterialName("Examples/Rockwall");

  collision = new CollisionTools();
  this->mRenderManager->forEachEntity([&](GameObject* gObj){collision->register_entity(gObj->getEntity(), Collision::COLLISION_BOX);});
  this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->initScript(collision);});

  /*this->mRenderManager->eraseEntities(static_cast<GameObject *>(this->mConfig->getPlayers().back()));
  collision->remove_entity(this->mConfig->getPlayers().back()->getEntity());
  this->mConfig->getPlayers().back()->unsetEntity(mSceneMgr);
  this->mConfig->getPlayers().pop_back();*/
}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool		ret = BaseGauntlet::frameRenderingQueued(fe);
  auto		it = _mmusic.find(this->_currentMusic);

  mKeyboard->capture();
  mMouse->capture();
  if (!processUnbufferedInput(fe))
    return false;
  if (_mmusic[this->_currentMusic]->getStatus() ==  sf::SoundSource::Status::Stopped)
  {
    if (it == _mmusic.end())
      throw IndieException("mMusic can't be load");
    if (++it == _mmusic.end())
      it = _mmusic.begin();
    this->setCurrMusicName(it->second->getCurrentName());
    it->second->setAudioVolume(15);
    it->second->playAudio();
  }
  /*mAnimationState->addTime(fe.timeSinceLastFrame);*/
  return ret;
}

void		GameCore::takeGoldStack(SCheckCollisionAnswer &collider, Pc *)
{
  GameObject			*tmp;

  if ((tmp = this->mRenderManager->searchEntities(collider.entity->getName())))
  {
    tmp->unsetEntity(mSceneMgr);
    mConfig->addScorePoint(100);
    _msound["gold"]->playAudio();
    this->mRenderManager->eraseEntities(tmp);
    collision->remove_entity(collider.entity);
  }
}

void		GameCore::takeKey(SCheckCollisionAnswer &collider, Pc *)
{
  GameObject			*tmp;

  if ((tmp = this->mRenderManager->searchEntities(collider.entity->getName())))
  {
    tmp->unsetEntity(mSceneMgr);
    this->_msound["key"]->playAudio();
    this->mConfig->addKey();
    this->mRenderManager->eraseEntities(tmp);
    this->collision->remove_entity(collider.entity);
  }
}

void		GameCore::takeFoodStack(SCheckCollisionAnswer &collider, Pc *player)
{
  GameObject	*tmp;

  if ((tmp = this->mRenderManager->searchEntities(collider.entity->getName())))
  {
    tmp->unsetEntity(mSceneMgr);
    player->gainHealth(50);
    _msound["food"]->playAudio();
    this->mRenderManager->eraseEntities(tmp);
    collision->remove_entity(collider.entity);
  }
}

void		GameCore::takeGate(SCheckCollisionAnswer &, Pc *)
{
  if (mConfig->getKey())
    exit(0);
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  Ogre::Vector3			dirVec = Ogre::Vector3::ZERO;
  Ogre::Vector3			CameraVec = Ogre::Vector3::ZERO;
  GameObject			*tmp;
  static Ogre::Real		toggleTimer = 0.0;
  std::stack<std::thread *>	threadPool;

  static bool actionKey = false;

  if (mConfig->getPlayers().empty() == true)
    exit (0);
  this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->launchScript(mSceneMgr, mConfig->getClosestPlayer(gObj), fe);});

  mConfig->forEachPlayer([&](Pc *player){this->_hud->updateLife(player->getHp(), player->getName());});
  this->_hud->updateScore(mConfig->getScore());
  this->_hud->updateKey(mConfig->getKey());
  this->_hud->showHUD();
  mConfig->forEachPlayer([&](Pc *player){
    if (player->isAlive() == false)
      destroyPlayer(player);
  });
  mConfig->forEachPlayer([&](Pc *player){player->Animate(fe);});

  for (auto itBinding = this->mKeyboardBinding.begin(); itBinding != this->mKeyboardBinding.end(); ++itBinding)
  {
    OIS::KeyCode	key	= itBinding->first;
    Pc			*player	= itBinding->second.first;
    eventType		event	= itBinding->second.second;

    if (mKeyboard->isKeyDown(key) && player->isAlive())
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
	    std::string		substring = collider.entity->getName().substr(0, 3);
	    dirVec.x -= 20 + player->getSpeed();

	    if (this->_lootEvent.find(substring) != this->_lootEvent.end())
	      this->_lootEvent[substring](collider, player);
	  }
	  else
	  {
	    itEvent->second(fe, dirVec, CameraVec, collision, mSceneMgr, mRenderManager, actionKey, player);
	    this->mCamera->move(CameraVec);
	  }
	  player->getSceneNode()->translate(dirVec * fe.timeSinceLastFrame, Ogre::Node::TS_LOCAL);
	  mCamera->setPosition(Ogre::Vector3(player->getSceneNode()->getPosition().x, 1500, player->getSceneNode()->getPosition().z -600));
	  /*mConfig->forEachPlayer([&](Pc *player){
	    if (player->isAlive() == false)
	      destroyPlayer(player);
	  });*/
	  toggleTimer -= fe.timeSinceLastFrame;
	  if (toggleTimer < 0)
	  {
	    toggleTimer = 1.5;
	    this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->setAttackStatus(false);});
	  }
	  return (true);
	}
      }
    }
  }
  actionKey = false;
  toggleTimer -= fe.timeSinceLastFrame;
  if (toggleTimer < 0)
  {
    toggleTimer = 1.5;
    this->mRenderManager->forEachEntity([&](GameObject* gObj){gObj->setAttackStatus(false);});
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

void GameCore::destroyPlayer(Pc *player)
{
  this->mRenderManager->eraseEntities(static_cast<GameObject*>(player));
  collision->remove_entity(player->getEntity());
  player->unsetEntity(mSceneMgr);
  this->mConfig->erasePlayer(player);
}
