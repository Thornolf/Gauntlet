/*
** GameCore.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 14 11:07:10 2017 Guillaume CAUCHOIS
** Last update Sat Jun 17 22:50:48 2017 Thomas Fossaert
*/

#ifndef		_GAME_CORE__HPP_
#define		_GAME_CORE__HPP_

# include <vector>
# include <stack>
# include <thread>
# include <Terrain/OgreTerrain.h>
# include <Terrain/OgreTerrainGroup.h>
# include "BaseGauntlet.hpp"
# include "Position.hpp"
# include "Animation.hpp"
# include "Audio/Music.hpp"
# include "Audio/SoundSystem.hpp"
# include "GameObject/Character/Npc/Zombie.hpp"
# include "GameObject/Character/Npc/Skeleton.hpp"
# include "GameObject/Doodad/Doodad.hpp"
# include "MapManager.hpp"

class GameCore : public BaseGauntlet
{
public:
  GameCore();
  virtual ~GameCore();

  void		setCurrMusicName(std::string);
  std::string		getCurrMusicName() const;
  void          destroyPlayer(Pc *);


private:
  void createScene(void);
  bool frameRenderingQueued(const Ogre::FrameEvent &);
  bool processUnbufferedInput(const Ogre::FrameEvent& );

  std::unordered_map<std::string, Music *>	_mmusic;
  std::unordered_map<std::string, Sound *>	_msound;
  std::string					_currentMusic;
  Ogre::AnimationState			*mAnimationState;
  Ogre::AnimationState			*mAnimationStateZombie;
  Ogre::Entity				*mEntity;
  Ogre::Entity				*mZombieEnt;
  Animation					*_animation;
  Ogre::SceneNode				*mNode;
  Ogre::SceneNode				*mZombie;
  Position					*mPosition;
  MapManager					*map;
  GameObject					*warrior;
};

#endif			/* !_GAME_CORE__HPP_! */
