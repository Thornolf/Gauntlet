/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
// Last update Fri May 26 10:57:04 2017 Thomas Fossaert
*/

#include "GameCore.hpp"
#include "Position.hpp"
#include "audio/Music.hpp"

GameCore::GameCore()
{
}

GameCore::~GameCore()
{
}

void GameCore::createScene()
{
  Music *music = new Music();
  music->playAudio("src/audio/all_star.ogg");
  mSceneMgr->setAmbientLight(Ogre::ColourValue(.25, .25, .25));

  Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
  pointLight->setType(Ogre::Light::LT_POINT);
  pointLight->setPosition(250, 150, 250);
  pointLight->setDiffuseColour(Ogre::ColourValue::Green);
  pointLight->setSpecularColour(Ogre::ColourValue::Green);

  Ogre::Entity* ninjaEntity = mSceneMgr->createEntity("penguin.mesh");
  Ogre::SceneNode* ninjaNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    "NinjaNode");
  ninjaNode->attachObject(ninjaEntity);

}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseGauntlet::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;

  return ret;
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  static bool mouseDownLastFrame = false;
  static Ogre::Real toggleTimer = 0.0;
  static Ogre::Real rotate = .13;
  static Ogre::Real move = 50;

  // First toggle method
  bool leftMouseDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);

  if (leftMouseDown && !mouseDownLastFrame)
  {
    Ogre::Light* light = mSceneMgr->getLight("PointLight");
    light->setVisible(!light->isVisible());
  }

  mouseDownLastFrame = leftMouseDown;

  // Second toggle method
  toggleTimer -= fe.timeSinceLastFrame;

  if ((toggleTimer < 0) && mMouse->getMouseState().buttonDown(OIS::MB_Right))
  {
    toggleTimer = .5;

    Ogre::Light* light = mSceneMgr->getLight("PointLight");
    light->setVisible(!light->isVisible());
  }

  // Moving the Ninja
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  if (mKeyboard->isKeyDown(OIS::KC_K))
    dirVec.x -= move;

  if (mKeyboard->isKeyDown(OIS::KC_M))
    dirVec.x += move;

  if (mKeyboard->isKeyDown(OIS::KC_O))
    dirVec.z += move;

  if (mKeyboard->isKeyDown(OIS::KC_L))
    dirVec.z -= move;

  if (mKeyboard->isKeyDown(OIS::KC_J))
  {
    if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
      mSceneMgr->getSceneNode("NinjaNode")->yaw(Ogre::Degree(5 * rotate));
    else
      dirVec.x -= move;
  }

  if (mKeyboard->isKeyDown(OIS::KC_U))
  {
    if (mKeyboard->isKeyDown(OIS::KC_LSHIFT))
      mSceneMgr->getSceneNode("NinjaNode")->yaw(Ogre::Degree(-5 * rotate));
    else
      dirVec.x += move;
  }

  mSceneMgr->getSceneNode("NinjaNode")->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);

  return true;
}
