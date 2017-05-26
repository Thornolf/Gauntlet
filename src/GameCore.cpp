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
  // Set the default lighting.
     mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
     // Create the entity
     mEntity = mSceneMgr->createEntity("Ninja", "ninja.mesh");

     // Create the scene node
     mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NinjaNode", Ogre::Vector3(0.0f, 0.0f, 25.0f));
     mNode->attachObject(mEntity);
     // Create the walking list
     mWalkList.push_back(Ogre::Vector3(550.0f,  0.0f,  50.0f ));
     mWalkList.push_back(Ogre::Vector3(-100.0f,  0.0f, -200.0f));
     // Create objects so we can see movement
     Ogre::Entity *ent;
     Ogre::SceneNode *node;

     ent = mSceneMgr->createEntity("Knot1", "robot.mesh");
     node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot1Node", Ogre::Vector3(0.0f, -10.0f,  25.0f));
     node->attachObject(ent);
     node->setScale(0.1f, 0.1f, 0.1f);

     ent = mSceneMgr->createEntity("Knot2", "robot.mesh");
     node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot2Node", Ogre::Vector3(550.0f, -10.0f,  50.0f));
     node->attachObject(ent);
     node->setScale(0.1f, 0.1f, 0.1f);

     ent = mSceneMgr->createEntity("Knot3", "robot.mesh");
     node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot3Node", Ogre::Vector3(-100.0f, -10.0f,-200.0f));
     node->attachObject(ent);
     node->setScale(0.1f, 0.1f, 0.1f);

     // Set the camera to look at our handiwork
     mCamera->setPosition(90.0f, 280.0f, 535.0f);
     mCamera->pitch(Ogre::Degree(-30.0f));
     mCamera->yaw(Ogre::Degree(-15.0f));

  Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

  Ogre::MeshManager::getSingleton().createPlane("ground",
  Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
  plane, 1500, 1500, 20, 20, true, 1, 5, 5,
  Ogre::Vector3::UNIT_Z);

  Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
  mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

  groundEntity->setMaterialName("Examples/Rockwall");
  /*mAnimationState = ninjaEntity->getAnimationState("Idle1");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);*/

}

void GameCore::createFrameListener(void)
{
    BaseGauntlet::createFrameListener();
    // Set idle animation
    mAnimationState = mEntity->getAnimationState("Idle1");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseGauntlet::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;
    /*mAnimationState = mEntity->getAnimationState("Walk");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);*/
  mAnimationState->addTime(fe.timeSinceLastFrame);

  return ret;
}

bool GameCore::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
  static bool mouseDownLastFrame = false;
  static Ogre::Real toggleTimer = 0.0;
  static Ogre::Real rotate = .13;
  static Ogre::Real move = 150;

  bool leftMouseDown = mMouse->getMouseState().buttonDown(OIS::MB_Left);

  if (leftMouseDown)
  {
    mAnimationState = mEntity->getAnimationState("Attack2");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
    mAnimationState->setLength(2);

  }
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  if (mKeyboard->isKeyDown(OIS::KC_K))
  {
    dirVec.x -= move;
    mAnimationState = mEntity->getAnimationState("Walk");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
  }

  if (mKeyboard->isKeyDown(OIS::KC_M))
  {
    dirVec.x += move;
    mAnimationState = mEntity->getAnimationState("Walk");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
  }

  if (mKeyboard->isKeyDown(OIS::KC_O))
  {
    dirVec.z += move;
    mAnimationState = mEntity->getAnimationState("Walk");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
  }

  if (mKeyboard->isKeyDown(OIS::KC_L))
  {
    dirVec.z -= move;
    mAnimationState = mEntity->getAnimationState("Walk");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
    if ((mNode->getOrientation()).getYaw() != Ogre::Degree(180))
      mNode->yaw(Ogre::Degree(180));
  }

  if (mKeyboard->isKeyDown(OIS::KC_SPACE))
  {
    mAnimationState = mEntity->getAnimationState("Jump");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
  }

  if (mKeyboard->isKeyDown(OIS::KC_I))
  {
    mAnimationState = mEntity->getAnimationState("Spin");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    mAnimationState->addTime(fe.timeSinceLastFrame);
  }

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
  mAnimationState = mEntity->getAnimationState("Idle1");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);
  return true;
}

void GameObject::hide(void) {}
