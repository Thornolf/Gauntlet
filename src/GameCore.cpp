/*
** GameCore.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
** Last update Fri Jun 02 11:38:29 2017 gratte_r
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
     mSceneMgr->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));
     mEntity = mSceneMgr->createEntity("Ninja", "ninja.mesh");

     mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("NinjaNode", Ogre::Vector3(100.0f, 0.0f, 25.0f));
     mNode->attachObject(mEntity);
		 mNode->setOrientation(-0.2, 0, 0.8, 0);

     Ogre::Entity *ent;
     Ogre::Entity *wall;
     Ogre::SceneNode *node;

     wall = mSceneMgr->createEntity("Cube", "cube.mesh");
     node = mSceneMgr->getRootSceneNode()->createChildSceneNode("CubeNode", Ogre::Vector3(0.0f, 50.0f,  750.0f));
     node->attachObject(wall);
     wall->setMaterialName("Examples/Rocky");
     node->setScale(15.0f, 7.0f, 0.3f);

     ent = mSceneMgr->createEntity("Ogre", "ogrehead.mesh");
     node = mSceneMgr->getRootSceneNode()->createChildSceneNode("OgreMesh", Ogre::Vector3(0.0f, 30.0f, 0.0f));
     node->attachObject(ent);
     node->setScale(3.0f, 3.0f, 3.0f);

     Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
     Ogre::MeshManager::getSingleton().createPlane("ground",
     Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
     plane, 1500, 1500, 20, 20, true, 1, 5, 5,
     Ogre::Vector3::UNIT_Z);
     Ogre::Entity* groundEntity = mSceneMgr->createEntity("ground");
     mSceneMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
     groundEntity->setMaterialName("Examples/Rockwall");


     collision = new CollisionTools();
     collision->register_entity(mEntity, Collision::COLLISION_SPHERE);
     collision->register_entity(wall, Collision::COLLISION_ACCURATE);
     collision->register_entity(ent, Collision::COLLISION_BOX);
}

void GameCore::createFrameListener(void)
{
    BaseGauntlet::createFrameListener();
    mAnimationState = mEntity->getAnimationState("Idle1");
    mAnimationState->setLoop(true);
    mAnimationState->setEnabled(true);
}

bool GameCore::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
  bool ret = BaseGauntlet::frameRenderingQueued(fe);

  if (!processUnbufferedInput(fe))
    return false;
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

  SCheckCollisionAnswer collider = collision->check_ray_collision(mSceneMgr->getSceneNode("NinjaNode")->getPosition(), mSceneMgr->getSceneNode("NinjaNode")->getPosition() + Ogre::Vector3(50.0f, 50.0f, 50.0f), 50.0f, 50.0f, 1, mEntity, true);

	if (collider.collided)
		{
			// if (mNode->getOrientation() == Ogre::Quaternion(1, 0, 0, 0))
			// 	mNode->setOrientation(Ogre::Quaternion(0, 0, -1, 0));
			// if (mNode->getOrientation() == Ogre::Quaternion(0, 0, -1, 0))
			// 	mNode->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
			// if (mNode->getOrientation() == Ogre::Quaternion(-0.7, 0, -0.7, 0))
			// 	mNode->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
			// if (mNode->getOrientation() == Ogre::Quaternion(-0.7, 0, 0.7, 0))
			// 	mNode->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
			dirVec.z += 2 + move;
		}
		std::cout << mNode->getOrientation().getYaw() << std::endl;
		mEntity->getBoundingBox();

			if (mKeyboard->isKeyDown(OIS::KC_O))
			{
				std::cout << "colllide up" << std::endl;
				mNode->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
				dirVec.z -= move;
				mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
			}
  	if (mKeyboard->isKeyDown(OIS::KC_K))
  	{
			mNode->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
			std::cout << "colllide left" << std::endl;
			dirVec.z -= move;
    	mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  	}
  	if (mKeyboard->isKeyDown(OIS::KC_M))
  	{
			mNode->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
			dirVec.z -= move;
			std::cout << "colllide right" << std::endl;
    	mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  	}

		// if (!collider.collided &&
		// 	((mNode->getOrientation().getYaw() < Ogre::Radian(1)) && (mNode->getOrientation().getYaw() > Ogre::Radian(-1))))
		// {
  		if (mKeyboard->isKeyDown(OIS::KC_L))
  			{
					std::cout << "colllide down" << std::endl;
					mNode->setOrientation(Ogre::Quaternion(0, 0, -1, 0));
					dirVec.z -= move;
    			mAnimationState = _animation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
  			}
		// }
		if (mKeyboard->isKeyDown(OIS::KC_J))
			{
				Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
  			mNode->yaw(Ogre::Degree(0.25));
			}
		if (mKeyboard->isKeyDown(OIS::KC_H))
			{
				Ogre::Vector3 src = mNode->getOrientation() * Ogre::Vector3::UNIT_X;
  			mNode->yaw(Ogre::Degree(-0.25));
			}
  mSceneMgr->getSceneNode("NinjaNode")->translate(
    dirVec * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);
  mAnimationState = mEntity->getAnimationState("Idle1");
  mAnimationState->setLoop(true);
  mAnimationState->setEnabled(true);
  return true;
}
