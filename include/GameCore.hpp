/*
** GameCore.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 14 11:07:10 2017 Guillaume CAUCHOIS
** Last update Wed Jun 14 15:26:30 2017 Robin Grattepanche
*/

#ifndef		_GAME_CORE__HPP_
#define		_GAME_CORE__HPP_

# include <Terrain/OgreTerrain.h>
# include <Terrain/OgreTerrainGroup.h>
# include <vector>
# include "BaseGauntlet.hpp"
# include "Position.hpp"
# include "Animation.hpp"
# include "GameObject/Character/Script.hpp"
# include "GameObject/Character/Npc/Zombie.hpp"
# include "GameObject/Character/Npc/Skeleton.hpp"
# include "GameObject/Doodad/Doodad.hpp"
# include "MapManager.hpp"

class GameCore : public BaseGauntlet
{
public:
  GameCore();
  virtual ~GameCore();
protected:
  virtual void createScene(void);
  virtual void createFrameListener(void);
  virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
  virtual bool processUnbufferedInput(const Ogre::FrameEvent& fe);

  /* Temporaire */
  CollisionTools	*collision;
  Ogre::AnimationState	*mAnimationState;
  Ogre::AnimationState	*mAnimationStateZombie;
  Ogre::Entity		*mEntity;
  Ogre::Entity		*mZombieEnt;
  Animation		*_animation;
  Ogre::SceneNode	*mNode;
  Ogre::SceneNode	*mZombie;
  Position		*mPosition;
  MapManager		*map;
};

#endif			/* !_GAME_CORE__HPP_! */
