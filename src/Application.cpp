/*
** Application.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
** Last update Thu May 25 17:08:09 2017 Thomas Fossaert
*/

#include "Application.h"
#include "Position.hpp"

Application::Application()
{
}

Application::~Application()
{
}

void Application::createScene()
{

  mSceneMgr->setAmbientLight(Ogre::ColourValue(.25, .25, .25));

	mSceneMgr->setSkyDome(true, "Examples/CloudySky");

  Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
  pointLight->setType(Ogre::Light::LT_POINT);
  pointLight->setPosition(250, 150, 250);
  pointLight->setDiffuseColour(Ogre::ColourValue::White);
  pointLight->setSpecularColour(Ogre::ColourValue::White);

  Ogre::Entity* penguinEntity = mSceneMgr->createEntity("penguin.mesh");
  Ogre::SceneNode* pinguinNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    "PinguinNode");
	pinguinNode->setPosition(/*pinguinPos->getVector()*/0, 0, 0);
  pinguinNode->attachObject(penguinEntity);

  mCamera->lookAt(0,0,0);
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane("ground",
	Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	plane, 1500, 1500, 20, 20, true, 1, 5, 5,
	Ogre::Vector3::UNIT_Z);

	// Ogre::SceneNode *cam = mSceneMgr->createChildSceneNode(Ogre::Vector3(0, 500, 350));
	// cam->attachObject(mCamera);

	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

	groundEntity->setMaterialName("Examples/Rockwall");

  Ogre::Entity *ninjaEntity = mSceneMgr->createEntity("ninja.mesh");
  Ogre::SceneNode* ninjaNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    "NinjaNode");;
  ninjaNode->setPosition(100, 50, 0);
  ninjaNode->attachObject(ninjaEntity);

}

bool Application::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseApplication::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;

  return ret;
}

bool Application::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  static bool mouseDownLastFrame = false;
  static Ogre::Real toggleTimer = 0.0;
  static Ogre::Real rotate = 0;
  static Ogre::Real move = 100;

  bool leftMouseDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);

  if (leftMouseDown && !mouseDownLastFrame)
  {
    Ogre::Light* light = mSceneMgr->getLight("PointLight");
    light->setVisible(!light->isVisible());
  }

  mouseDownLastFrame = leftMouseDown;

  toggleTimer -= fe.timeSinceLastFrame;

  if ((toggleTimer < 0) && mMouse->getMouseState().buttonDown(OIS::MB_Right))
  {
    toggleTimer = .5;

    Ogre::Light* light = mSceneMgr->getLight("PointLight");
    light->setVisible(!light->isVisible());
  }


  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
  Ogre::Vector3 dirVec2 = Ogre::Vector3::ZERO;

  if (mKeyboard->isKeyDown(OIS::KC_K))
    {
			dirVec.x -= move;
		}

  if (mKeyboard->isKeyDown(OIS::KC_M))
		{
      dirVec.x += move;
		}

  if (mKeyboard->isKeyDown(OIS::KC_L))
    dirVec.z += move;

  if (mKeyboard->isKeyDown(OIS::KC_O))
    {
      dirVec.z -= move;
		}

  mSceneMgr->getSceneNode("PinguinNode")->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);

  mSceneMgr->getSceneNode("PinguinNode")->yaw(
    Ogre::Degree(rotate * fe.timeSinceLastFrame));

    dirVec2.z += 10;
  mSceneMgr->getSceneNode("NinjaNode")->translate(
      dirVec2 * fe.timeSinceLastFrame,
      Ogre::Node::TS_LOCAL);

mCamera->setPosition(mCamera->getPosition() + dirVec);
		rotate = 0;
  return true;
}
