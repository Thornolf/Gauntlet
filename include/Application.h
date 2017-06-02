/*
-----------------------------------------------------------------------------
Filename:    Application.h
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
-----------------------------------------------------------------------------
*/
#ifndef __Application_h_
#define __Application_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>

#include "BaseApplication.h"
#include "Position.hpp"

class Application : public BaseApplication
{
public:
  Application();
  virtual ~Application();
protected:
  virtual void createScene(void);
    virtual void createFrameListener(void);

    virtual bool frameRenderingQueued(const Ogre::FrameEvent &evt);
    virtual bool nextLocation(void);

    Ogre::Real mDistance;                  // The distance the object has left to travel
    Ogre::Vector3 mDirection;              // The direction the object is moving
    Ogre::Vector3 mDestination;            // The destination the object is moving towards

    Ogre::AnimationState *mAnimationState; // The current animation state of the object

    Ogre::Entity *mEntity;                 // The Entity we are animating
    Ogre::SceneNode *mNode;                // The -SceneNode that the Entity is attached to
    std::deque<Ogre::Vector3> mWalkList;   // The list of points we are walking to
    Position *mPos;

    Ogre::Real mWalkSpeed;
};

#endif // #ifndef __Application_h_
