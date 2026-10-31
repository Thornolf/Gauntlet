/*
** BaseGauntlet.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 02 06:35:26 2017 Guillaume CAUCHOIS
// Last update Sat Jun 17 12:03:18 2017 Thomas Fossaert
*/

#include <filesystem>
#include "BaseGauntlet.hpp"

#ifdef _WIN32
# include <cstring>
# include <windows.h>

// myKeyboard.cnf uses OIS key codes for letters ("KC_Z" = the key printed Z),
// which is what OIS reports on Linux. On Windows OIS reports the physical key
// position (US QWERTY), so move each letter to where it is on this layout.
static std::map<OIS::KeyCode, std::pair<Pc *, eventType> >
remapLettersToKeyboardLayout(const std::map<OIS::KeyCode, std::pair<Pc *, eventType> > &binding)
{
  static const std::pair<int, const char *>	rows[] = {
    {OIS::KC_Q, "QWERTYUIOP"}, {OIS::KC_A, "ASDFGHJKL"}, {OIS::KC_Z, "ZXCVBNM"}
  };
  std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	result;

  for (const auto &it : binding)
  {
    OIS::KeyCode	key = it.first;
    for (const auto &row : rows)
    {
      int	pos = key - row.first;
      if (pos >= 0 && pos < static_cast<int>(std::strlen(row.second)))
      {
	SHORT	vk = VkKeyScanA(row.second[pos]);
	UINT	scan = (vk == -1) ? 0 : MapVirtualKeyA(vk & 0xff, MAPVK_VK_TO_VSC);
	if (scan != 0)
	  key = static_cast<OIS::KeyCode>(scan);
	break;
      }
    }
    result[key] = it.second;
  }
  return result;
}
#endif

BaseGauntlet::BaseGauntlet(void)
  : mRoot(0),
    mCamera(0),
    mCameraNode(0),
    mSceneMgr(0),
    mWindow(0),
    mResourcesCfg(Ogre::BLANKSTRING),
    mPluginsCfg(Ogre::BLANKSTRING),
    mShutDown(false),
    mInputManager(0),
    mMouse(0),
    mKeyboard(0)
{
  Pc			*unitPlayer;

  collision = new CollisionTools();
  mRenderManager = new RenderManager();
  mConfig = new Configuration();

  unitPlayer = static_cast<Pc*>(mRenderManager->createGameObject("TANK", Position(-100, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  mConfig->addPlayer(unitPlayer);
  unitPlayer = static_cast<Pc*>(mRenderManager->createGameObject("MAGE", Position(200, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  mConfig->addPlayer(unitPlayer);
  unitPlayer = static_cast<Pc*>(mRenderManager->createGameObject("ARCHER", Position(400, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  mConfig->addPlayer(unitPlayer);
  unitPlayer = static_cast<Pc*>(mRenderManager->createGameObject("WARRIOR", Position(-400, 0, 500), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), ""));
  mConfig->addPlayer(unitPlayer);
}

//------------------------------------------------------------------------------------
BaseGauntlet::~BaseGauntlet(void)
{
  OgreBites::WindowEventUtilities::removeWindowEventListener(mWindow, this);
  windowClosed(mWindow);
  delete mRoot;
}

//-------------------------------------------------------------------------------------
bool BaseGauntlet::configure(void)
{
  // Reuse the settings saved in ogre.cfg, otherwise ask for them
  bool restored = false;
  try
  {
    restored = mRoot->restoreConfig();
  }
  catch (const Ogre::Exception &)
  {
    // ogre.cfg made by another Ogre version: just ask again
  }
  if(restored || mRoot->showConfigDialog(OgreBites::getNativeConfigDialog()))
  {
    mWindow = mRoot->initialise(true, "Gauntlet");
    return true;
  }
  else
    return false;
}
//-------------------------------------------------------------------------------------
void BaseGauntlet::chooseSceneManager(void)
{
  mOverlaySystem = new Ogre::OverlaySystem();
  mSceneMgr = mRoot->createSceneManager();
  mSceneMgr->addRenderQueueListener(mOverlaySystem);
}



//-------------------------------------------------------------------------------------
void BaseGauntlet::createCamera(void)
{
  mCamera = mSceneMgr->createCamera("PlayerCam");
  mCamera->setNearClipDistance(5);
  mCameraNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  mCameraNode->attachObject(mCamera);
  // Keep the horizon level like Ogre::Camera did, otherwise lookAt() takes the
  // shortest rotation and the view ends up upside down
  mCameraNode->setFixedYawAxis(true);
  mCameraNode->setPosition(Ogre::Vector3(0,1500,-700));
  mCameraNode->lookAt(Ogre::Vector3(0,0,0), Ogre::Node::TS_WORLD);
}
//-------------------------------------------------------------------------------------
void BaseGauntlet::createFrameListener(void)
{
  Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");
  OIS::ParamList	pl;
  size_t		windowHnd = 0;
  std::ostringstream	windowHndStr;

  mWindow->getCustomAttribute("WINDOW", &windowHnd);
  windowHndStr << windowHnd;
  pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));

  mInputManager = OIS::InputManager::createInputSystem(pl);
  mInputParser = new ParserInputFile();
  mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject( OIS::OISKeyboard, true ));
  mKeyboardBinding = mInputParser->getArrayBindingFromFile("myKeyboard.cnf", mConfig->getPlayers());
#ifdef _WIN32
  mKeyboardBinding = remapLettersToKeyboardLayout(mKeyboardBinding);
#endif
  mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));

  mMouse->setEventCallback(this);
  mKeyboard->setEventCallback(this);

  windowResized(mWindow);
  OgreBites::WindowEventUtilities::addWindowEventListener(mWindow, this);

  mRoot->addFrameListener(this);
}


//-------------------------------------------------------------------------------------
void BaseGauntlet::destroyScene(void)
{
}
//-------------------------------------------------------------------------------------
void BaseGauntlet::createViewports(void)
{
  Ogre::Viewport* vp = mWindow->addViewport(mCamera);
  vp->setBackgroundColour(Ogre::ColourValue(0,0,0));

  mCamera->setAspectRatio(
    Ogre::Real(vp->getActualWidth()) / Ogre::Real(vp->getActualHeight()));
}
//-------------------------------------------------------------------------------------
void BaseGauntlet::setupResources(void)
{
  Ogre::ConfigFile cf;
  cf.load(mResourcesCfg);

  for (const auto &section : cf.getSettingsBySection())
  {
    for (const auto &setting : section.second)
    {
      // Skip folders that don't exist on this machine (e.g. old CEGUI paths)
      if (setting.first == "FileSystem" && !std::filesystem::exists(setting.second))
	continue;
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
	setting.second, setting.first, section.first);
    }
  }
}
//-------------------------------------------------------------------------------------
void BaseGauntlet::createResourceListener(void)
{

}
//-------------------------------------------------------------------------------------
void BaseGauntlet::loadResources(void)
{
  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}
//-------------------------------------------------------------------------------------
void BaseGauntlet::go(void)
{
  mResourcesCfg = "resources.cfg";
  // A packaged game ships its own plugins.cfg, a build uses the generated one
  mPluginsCfg = "plugins.cfg";
#ifdef GAUNTLET_PLUGINS_CFG
  if (!std::filesystem::exists(mPluginsCfg))
    mPluginsCfg = GAUNTLET_PLUGINS_CFG;
#endif

  if (!setup())
    return;
  // Ogre >= 1.10 no longer pumps the window messages itself
  while (!mShutDown && !mWindow->isClosed())
  {
    OgreBites::WindowEventUtilities::messagePump();
    if (!mRoot->renderOneFrame())
      break;
  }

  // clean up
  destroyScene();
}
//-------------------------------------------------------------------------------------
bool BaseGauntlet::setup(void)
{
  mRoot = new Ogre::Root(mPluginsCfg, "ogre.cfg", "Ogre.log");

  setupResources();

  bool carryOn = configure();
  if (!carryOn) return false;

  chooseSceneManager();
  createCamera();
  createViewports();

  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);

  createResourceListener();
  loadResources();

  createScene();

  createFrameListener();

  return true;
};
//-------------------------------------------------------------------------------------
bool BaseGauntlet::frameRenderingQueued(const Ogre::FrameEvent& evt)
{
  if(mWindow->isClosed())
    return false;
  if(mShutDown)
    return false;

  (void)evt;
  return true;
}
//-------------------------------------------------------------------------------------
bool BaseGauntlet::keyPressed( const OIS::KeyEvent &arg)
{
  if (arg.key == OIS::KC_SYSRQ)
    mWindow->writeContentsToTimestampedFile("screenshot", ".jpg");
  else if (arg.key == OIS::KC_ESCAPE || arg.key == OIS::KC_LMENU)
    mShutDown = true;
  return true;
}

bool BaseGauntlet::keyReleased( const OIS::KeyEvent & )
{
  return true;
}

bool BaseGauntlet::mouseMoved( const OIS::MouseEvent & )
{
  return true;
}

bool BaseGauntlet::mousePressed( const OIS::MouseEvent &, OIS::MouseButtonID )
{
  return true;
}

bool BaseGauntlet::mouseReleased( const OIS::MouseEvent &, OIS::MouseButtonID )
{
  return true;
}

void BaseGauntlet::windowResized(Ogre::RenderWindow* rw)
{
  unsigned int width = rw->getWidth();
  unsigned int height = rw->getHeight();

  if (!mMouse)
    return;
  const OIS::MouseState &ms = mMouse->getMouseState();
  ms.width = width;
  ms.height = height;
}

void BaseGauntlet::windowClosed(Ogre::RenderWindow* rw)
{
  if (rw == mWindow)
  {
    if (mInputManager)
    {
      mInputManager->destroyInputObject(mMouse);
      mInputManager->destroyInputObject(mKeyboard);

      OIS::InputManager::destroyInputSystem(mInputManager);
      mInputManager = 0;
    }
  }
}
