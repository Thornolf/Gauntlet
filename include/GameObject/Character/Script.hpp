/*
** Script.hpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:25:19 2017 Adrien Warin
** Last update Mon Jun 05 16:18:01 2017 Thomas Fossaert
*/

#ifndef SCRIPT_HPP_
# define SCRIPT_HPP_

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

class Script
{

public:
  Script ();
  virtual ~Script ();
  Ogre::Vector3 ZombieScript(Ogre::SceneNode *,Ogre::SceneNode *);
  Ogre::Vector3 SkeletonScript(Ogre::SceneNode *,Ogre::SceneNode *);
  Ogre::Vector3 BossScript(Ogre::SceneNode *,Ogre::SceneNode *);
  void test();
};

#endif
