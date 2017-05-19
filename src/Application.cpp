/*
** Application.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:02:47 2017 Thomas Fossaert
** Last update Fri May 19 15:03:21 2017 Thomas Fossaert
*/

#include "Application.h"

Application::Application(void)
{
}

Application::~Application(void)
{
}

void Application::createScene(void)
{
  mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5, 0.5, 0.5));
  Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
  Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  ogreNode->attachObject(ogreEntity);
  Ogre::Light* light = mSceneMgr->createLight("MainLight");
  light->setPosition(20, 80, 50);

  mCamera->setPosition(0, 47, 222);
  Ogre::Entity* ogreEntity2 = mSceneMgr->createEntity("ogrehead.mesh");

  Ogre::SceneNode* ogreNode2 = ogreNode->createChildSceneNode(
  Ogre::Vector3(84, 48, 0));
  ogreNode2->attachObject(ogreEntity2);

  Ogre::Entity* ogreEntity3 = mSceneMgr->createEntity("ogrehead.mesh");

  Ogre::SceneNode* ogreNode3 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  ogreNode3->setPosition(0, 104, 0);
  ogreNode3->setScale(2, 1.2, 1);
  ogreNode3->attachObject(ogreEntity3);

  Ogre::Entity* ogreEntity4 = mSceneMgr->createEntity("ogrehead.mesh");

  Ogre::SceneNode* ogreNode4 = mSceneMgr->getRootSceneNode()->createChildSceneNode();
  ogreNode4->setPosition(-84, 48, 0);
  ogreNode4->roll(Ogre::Degree(-90));
  ogreNode4->attachObject(ogreEntity4);
}
