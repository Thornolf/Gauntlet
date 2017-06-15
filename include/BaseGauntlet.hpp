/*
** BaseGauntlet.hpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 02 06:31:36 2017 Guillaume CAUCHOIS
** Last update Wed Jun 14 15:14:53 2017 Robin Grattepanche
*/

#ifndef		__BASEGAUNTLET__HPP_
# define	__BASEGAUNTLET__HPP_

# include <OgreCamera.h>
# include <OgreEntity.h>
# include <OgreLogManager.h>
# include <OgreRoot.h>
# include <OgreViewport.h>
# include <OgreSceneManager.h>
# include <OgreRenderWindow.h>
# include <OgreConfigFile.h>

# include <OISEvents.h>
# include <OISInputManager.h>
# include <OISKeyboard.h>
# include <OISMouse.h>

# include <SdkTrays.h>
# include <SdkCameraMan.h>

# include "NewMOC.hpp"
# include "Configuration.hpp"
# include "Input/ParserInputFile.hpp"
# include "Input/eventType.hpp"
# include "Animation.hpp"
# include "GameObject/Character/Pc/Pc.hpp"
# include "RenderManager.hpp"

using namespace Collision;

class BaseGauntlet : public Ogre::FrameListener, public Ogre::WindowEventListener, public OIS::KeyListener, public OIS::MouseListener, OgreBites::SdkTrayListener
{
public:
  BaseGauntlet(void);
  virtual ~BaseGauntlet(void);

  virtual void go(void);

protected:
  virtual bool setup();
  virtual bool configure(void);
  virtual void chooseSceneManager(void);
  virtual void createCamera(void);
  virtual void createFrameListener(void);
  virtual void createScene(void) = 0; // Override me!
  virtual void destroyScene(void);
  virtual void createViewports(void);
  virtual void setupResources(void);
  virtual void createResourceListener(void);
  virtual void loadResources(void);

  virtual bool frameRenderingQueued(const Ogre::FrameEvent& evt);

  virtual bool keyPressed( const OIS::KeyEvent &arg );
  virtual bool keyReleased( const OIS::KeyEvent &arg );
  virtual bool mouseMoved( const OIS::MouseEvent &arg );
  virtual bool mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id );
  virtual bool mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id );

  virtual void windowResized(Ogre::RenderWindow* rw);
  virtual void windowClosed(Ogre::RenderWindow* rw);

  Ogre::Root			*mRoot;
  Ogre::Camera*			mCamera;
  Ogre::SceneManager*		mSceneMgr;
  Ogre::RenderWindow*		mWindow;
  Ogre::String			mResourcesCfg;
  Ogre::String			mPluginsCfg;
  Ogre::OverlaySystem		*mOverlaySystem;

  // Configuration
  Configuration			*mConfig;
  RenderManager			*mRenderManager;

  // OgreBites
  OgreBites::SdkTrayManager*					mTrayMgr;
  OgreBites::SdkCameraMan*					mCameraMan;
  OgreBites::ParamsPanel*					mDetailsPanel;
  bool								mCursorWasVisible;
  bool								mShutDown;

  //OIS Input devices
  ParserInputFile						*mInputParser;
  OIS::InputManager						*mInputManager;
  OIS::Mouse							*mMouse;
  OIS::Keyboard*						mKeyboard;
  std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	mKeyboardBinding;

  Ogre::AnimationState*		mAnimationState;

  // Collision
  CollisionTools*		collision;
};

#endif		/* !_BASEGAUNTLET__HPP_ */
