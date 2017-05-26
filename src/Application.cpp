/*
** Application.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
** Last update Fri May 26 10:22:13 2017 Thomas Fossaert
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
  // Set the default lighting.
      mPos = new Position(0, 250, 0);
      mPos->setPosition(0, 250, 0);
      Ogre::Vector3 pos = mPos->getVector();
      mSceneMgr->setSkyDome(true, "Examples/CloudySky");

      mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
      // Create the entity
      mEntity = mSceneMgr->createEntity("Robot", "ninja.mesh");

      // Create the scene node
      mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("RobotNode", Ogre::Vector3(0.0f, 0.0f, 25.0f));
      mNode->attachObject(mEntity);
      // Create the walking list
      mWalkList.push_back(Ogre::Vector3(550.0f,  0.0f,  50.0f ));
      mWalkList.push_back(Ogre::Vector3(-100.0f,  0.0f, -200.0f));
      // Create objects so we can see movement
      Ogre::Entity *ent;
      Ogre::SceneNode *node;

      ent = mSceneMgr->createEntity("Knot1", "knot.mesh");
      node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot1Node", Ogre::Vector3(0.0f, -10.0f,  25.0f));
      node->attachObject(ent);
      node->setScale(0.1f, 0.1f, 0.1f);

      ent = mSceneMgr->createEntity("Knot2", "knot.mesh");
      node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot2Node", Ogre::Vector3(550.0f, -10.0f,  50.0f));
      node->attachObject(ent);
      node->setScale(0.1f, 0.1f, 0.1f);

      ent = mSceneMgr->createEntity("Knot3", "knot.mesh");
      node = mSceneMgr->getRootSceneNode()->createChildSceneNode("Knot3Node", Ogre::Vector3(-100.0f, -10.0f,-200.0f));
      node->attachObject(ent);
      node->setScale(0.1f, 0.1f, 0.1f);

      Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

    	Ogre::MeshManager::getSingleton().createPlane("ground",
    	Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
    	plane, 1500, 1500, 20, 20, true, 1, 5, 5,
    	Ogre::Vector3::UNIT_Z);

    	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
    	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

    	groundEntity->setMaterialName("Examples/Rockwall");

      // Set the camera to look at our handiwork
      mCamera->setPosition(0, 230, 0);
      /*mCamera->pitch(Ogre::Degree(-30.0f));
      mCamera->yaw(Ogre::Degree(-15.0f));*/

  }
  /*void Application::createFrameListener(void){
      BaseApplication::createFrameListener();
      mAnimationState = mEntity->getAnimationState("Idle");
      mAnimationState->setLoop(true);
      mAnimationState->setEnabled(true);
      mWalkSpeed = 35.0f;
      mDirection = Ogre::Vector3::ZERO;*/
/*  mSceneMgr->setAmbientLight(Ogre::ColourValue(.25, .25, .25));

	mSceneMgr->setSkyDome(true, "Examples/CloudySky");

  Ogre::Light* pointLight = mSceneMgr->createLight("PointLight");
  pointLight->setType(Ogre::Light::LT_POINT);
  pointLight->setPosition(250, 150, 250);
  pointLight->setDiffuseColour(Ogre::ColourValue::White);
  pointLight->setSpecularColour(Ogre::ColourValue::White);

  Ogre::Entity* penguinEntity = mSceneMgr->createEntity("penguin.mesh");
  Ogre::SceneNode* pinguinNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    "PinguinNode");
	pinguinNode->setPosition(0, 0, 0);
  pinguinNode->attachObject(penguinEntity);

  mCamera->lookAt(0,0,0);
	Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);

	Ogre::MeshManager::getSingleton().createPlane("ground",
	Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
	plane, 1500, 1500, 20, 20, true, 1, 5, 5,
	Ogre::Vector3::UNIT_Z);

	Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
	mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);

	groundEntity->setMaterialName("Examples/Rockwall");

  Ogre::Entity *ninjaEntity = mSceneMgr->createEntity("ninja.mesh");
  Ogre::SceneNode* ninjaNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(
    "NinjaNode");;
  ninjaNode->setPosition(100, 50, 0);*/
//}

void Application::createFrameListener(void)
{
    BaseApplication::createFrameListener();
    // Set idle animation
    mAnimationState = mEntity->getAnimationState("Idle1");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
    // Set default values for variables
    mWalkSpeed = 35.0f;
    mDirection = Ogre::Vector3::ZERO;
}
bool Application::nextLocation(void){
    if (mWalkList.empty()) return false;
    mDestination = mWalkList.front();  // this gets the front of the deque
    mWalkList.pop_front();             // this removes the front of the deque
    mDirection = mDestination - mNode->getPosition();
    mDistance = mDirection.normalise();
    return true;
}

bool Application::frameRenderingQueued(const Ogre::FrameEvent &evt){
    	if (mDirection == Ogre::Vector3::ZERO) {
		if (nextLocation())
    {
			mAnimationState = mEntity->getAnimationState("Block");
			mAnimationState->setLoop(true);
			mAnimationState->setEnabled(true);
		}
	}else{
		Ogre::Real move = mWalkSpeed * evt.timeSinceLastFrame;
		mDistance -= move;
		if (mDistance <= 0.0f){
			mNode->setPosition(mDestination);
			mDirection = Ogre::Vector3::ZERO;
			// Set animation based on if the robot has another point to walk to.
			if (!nextLocation()){
				// Set Idle animation
				mAnimationState = mEntity->getAnimationState("Idle2");
				mAnimationState->setLoop(true);
				mAnimationState->setEnabled(true);
			}else{
				// Rotation Code will go here later
				Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
				if ((1.0f + src.dotProduct(mDirection)) < 0.0001f) {
					mNode->yaw(Ogre::Degree(180));
				}else{
					Ogre::Quaternion quat = src.getRotationTo(mDirection);
					mNode->rotate(quat);
				} // else
			}//else
		}else{
			mNode->translate(mDirection * move);
		} // else
	} // if
	mAnimationState->addTime(evt.timeSinceLastFrame);
	return BaseApplication::frameRenderingQueued(evt);
}
