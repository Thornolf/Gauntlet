/*
-----------------------------------------------------------------------------
Filename:    GameCore.h
-----------------------------------------------------------------------------

This source file is part of the
   ___                 __    __ _ _    _
  /___\__ _ _ __ ___  / / /\ \ (_) | _(_)
 //  // _` | '__/ _ \ \ \/  \/ / | |/ / |
/ \_// (_| | | |  __/  \  /\  /| |   <| |
\___/ \__, |_|  \___|   \/  \/ |_|_|\_\_|
      |___/
      Tutorial Framework
      http://www.ogre3d.org/tikiwiki/
----------------------------------------------------------------------------
*/
#ifndef __GameCore_h_
#define __GameCore_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>
#include <vector>

#include "BaseGauntlet.hpp"
#include "Position.hpp"
#include "Animation.hpp"
#include "GameObject/Character/Script.hpp"
#include "GameObject/Character/Npc/Zombie.hpp"
#include "GameObject/Character/Npc/Skeleton.hpp"
#include "MapManager.hpp"
#include "RenderManager.hpp"

class GameCore : public BaseGauntlet
{
public:
  GameCore();
  virtual ~GameCore();
protected:
    virtual void createScene(void);
    virtual void createFrameListener(void);

    virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
    //virtual bool nextLocation(void);
    virtual bool processUnbufferedInput(const Ogre::FrameEvent& fe);


    Ogre::Real mDistance;                  // The distance the object has left to travel
    Ogre::Vector3 mDirection;              // The direction the object is moving
    Ogre::Vector3 mDestination;            // The destination the object is moving towards

		CollisionTools *collision;

    Ogre::AnimationState *mAnimationState; // The current animation state of the object
    Ogre::AnimationState *mAnimationStateZombie; // The current animation state of the object

    Ogre::Entity *mEntity;                 // The Entity we are animating
    Ogre::Entity *mZombieEnt;                 // The Entity we are animating

    Animation *_animation;
    Ogre::SceneNode *mNode;                // The -SceneNode that the Entity is attached to
    Ogre::SceneNode *mZombie;                // The -SceneNode that the Entity is attached to


    Script *mScript;
    Position *mPosition;
    Zombie *mZob;
    MapManager *map;
    RenderManager render;;
};

#endif // #ifndef __GameCore_h_
