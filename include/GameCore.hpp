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
-----------------------------------------------------------------------------
*/
#ifndef __GameCore_h_
#define __GameCore_h_

#include <Terrain/OgreTerrain.h>
#include <Terrain/OgreTerrainGroup.h>

#include "BaseGauntlet.hpp"

class GameCore : public BaseGauntlet
{
public:
  GameCore();
  virtual ~GameCore();
protected:
  virtual void createScene();
  virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);
private:
  bool processUnbufferedInput(const Ogre::FrameEvent& fe);
};

#endif // #ifndef __GameCore_h_
