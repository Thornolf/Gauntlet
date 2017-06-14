/*
** Script.hpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:25:19 2017 Adrien Warin
** Last update Wed Jun 14 11:31:24 2017 Thomas Fossaert
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

#include "NewMOC.hpp"

using namespace Collision;

class Script
{
private:
  CollisionTools* _collision;
  Ogre::Entity *_entity;

public:
  Script ();

  virtual ~Script ();
  Ogre::Vector3 ZombieScript(Ogre::SceneNode *,Ogre::SceneNode *);
  Ogre::Vector3 SkeletonScript(Ogre::SceneNode *,Ogre::SceneNode *);
  Ogre::Vector3 BossScript(Ogre::SceneNode *,Ogre::SceneNode *);
  void setCollision(CollisionTools *collision, Ogre::Entity* ent);
};

#endif
