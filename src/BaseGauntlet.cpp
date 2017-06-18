/*
** BaseGauntlet.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 02 06:35:26 2017 Guillaume CAUCHOIS
// Last update Sat Jun 17 12:03:18 2017 Thomas Fossaert
*/

#include "BaseGauntlet.hpp"

BaseGauntlet::BaseGauntlet(void)
  : mRoot(0),
    mCamera(0),
    mSceneMgr(0),
    mWindow(0),
    mResourcesCfg(Ogre::StringUtil::BLANK),
    mPluginsCfg(Ogre::StringUtil::BLANK),
    mTrayMgr(0),
    mCameraMan(0),
    mDetailsPanel(0),
    mCursorWasVisible(false),
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
  if (mTrayMgr) delete mTrayMgr;
  if (mCameraMan) delete mCameraMan;

  Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
  windowClosed(mWindow);
  delete mRoot;
}

//-------------------------------------------------------------------------------------
bool BaseGauntlet::configure(void)
{
  if(mRoot->showConfigDialog())
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
  mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);
  mOverlaySystem = new Ogre::OverlaySystem();
  mSceneMgr->addRenderQueueListener(mOverlaySystem);
}



//-------------------------------------------------------------------------------------
void BaseGauntlet::createCamera(void)
{
  mCamera = mSceneMgr->createCamera("PlayerCam");
  mCamera->setPosition(Ogre::Vector3(0,1500,-700));
  mCamera->lookAt(Ogre::Vector3(0,0,0));
  mCamera->setNearClipDistance(5);
  mCameraMan = new OgreBites::SdkCameraMan(mCamera);   // create a default camera controller
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
  mMouse = static_cast<OIS::Mouse*>(mInputManager->createInputObject( OIS::OISMouse, true ));

  mMouse->setEventCallback(this);
  mKeyboard->setEventCallback(this);

  windowResized(mWindow);
  Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

OgreBites::InputContext inputContext;
 inputContext.mMouse = mMouse;
 inputContext.mKeyboard = mKeyboard;
 mTrayMgr = new OgreBites::SdkTrayManager("InterfaceName", mWindow, inputContext, this);
  mTrayMgr->hideCursor();

  Ogre::StringVector items;
  items.push_back("cam.pX");
  items.push_back("cam.pY");
  items.push_back("cam.pZ");
  items.push_back("");
  items.push_back("cam.oW");
  items.push_back("cam.oX");
  items.push_back("cam.oY");
  items.push_back("cam.oZ");
  items.push_back("");
  items.push_back("Filtering");
  items.push_back("Poly Mode");

  mDetailsPanel = mTrayMgr->createParamsPanel(OgreBites::TL_NONE, "DetailsPanel", 200, items);
  mDetailsPanel->setParamValue(9, "Bilinear");
  mDetailsPanel->setParamValue(10, "Solid");
  mDetailsPanel->hide();
  mRoot->addFrameListener(this);
}

//------------------------------------------------------------------------------------

void BaseGauntlet::buttonHit(OgreBites::Button *button)
{
    if (button->getName() == "Test")
    	mTrayMgr->moveWidgetToTray("Test", OgreBites::TL_BOTTOMLEFT);
		if (button->getName() == "Truc")
			mTrayMgr->moveWidgetToTray("Truc", OgreBites::TL_TOPLEFT);
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

  Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();

  Ogre::String secName, typeName, archName;
  while (seci.hasMoreElements())
  {
    secName = seci.peekNextKey();
    Ogre::ConfigFile::SettingsMultiMap *settings = seci.getNext();
    Ogre::ConfigFile::SettingsMultiMap::iterator i;
    for (i = settings->begin(); i != settings->end(); ++i)
    {
      typeName = i->first;
      archName = i->second;
      Ogre::ResourceGroupManager::getSingleton().addResourceLocation(
	archName, typeName, secName);
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
#ifdef _DEBUG
  mResourcesCfg = "resources_d.cfg";
  mPluginsCfg = "plugins_d.cfg";
#else
  mResourcesCfg = "resources.cfg";
  mPluginsCfg = "plugins.cfg";
#endif

  if (!setup())
    return;
  mRoot->startRendering();

  // clean up
  destroyScene();
}
//-------------------------------------------------------------------------------------
bool BaseGauntlet::setup(void)
{
  mRoot = new Ogre::Root(mPluginsCfg);

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

  mTrayMgr->refreshCursor();
  mTrayMgr->frameRenderingQueued(evt);

  if (!mTrayMgr->isDialogVisible())
  {
    mCameraMan->frameRenderingQueued(evt);
    if (mDetailsPanel->isVisible())
    {
      mDetailsPanel->setParamValue(0, Ogre::StringConverter::toString(mCamera->getDerivedPosition().x));
      mDetailsPanel->setParamValue(1, Ogre::StringConverter::toString(mCamera->getDerivedPosition().y));
      mDetailsPanel->setParamValue(2, Ogre::StringConverter::toString(mCamera->getDerivedPosition().z));
      mDetailsPanel->setParamValue(4, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().w));
      mDetailsPanel->setParamValue(5, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().x));
      mDetailsPanel->setParamValue(6, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().y));
      mDetailsPanel->setParamValue(7, Ogre::StringConverter::toString(mCamera->getDerivedOrientation().z));
    }
  }
  return true;
}
//-------------------------------------------------------------------------------------
bool BaseGauntlet::keyPressed( const OIS::KeyEvent &arg )
{
  if (arg.key == OIS::KC_SYSRQ)
    mWindow->writeContentsToTimestampedFile("screenshot", ".jpg");
  else if (arg.key == OIS::KC_ESCAPE)
    mShutDown = true;
  // mCameraMan->injectKeyDown(arg);
  return true;
}

bool BaseGauntlet::keyReleased( const OIS::KeyEvent &arg )
{
  mCameraMan->injectKeyUp(arg);
  return true;
}

bool BaseGauntlet::mouseMoved( const OIS::MouseEvent &arg )
{
  return true;
}

bool BaseGauntlet::mousePressed( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
  if (mTrayMgr->injectMouseDown(arg, id)) return true;
  mCameraMan->injectMouseDown(arg, id);
  return true;
}

bool BaseGauntlet::mouseReleased( const OIS::MouseEvent &arg, OIS::MouseButtonID id )
{
  if (mTrayMgr->injectMouseUp(arg, id)) return true;
  mCameraMan->injectMouseUp(arg, id);
  return true;
}

void BaseGauntlet::windowResized(Ogre::RenderWindow* rw)
{
  unsigned int width, height, depth;
  int left, top;
  rw->getMetrics(width, height, depth, left, top);

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
