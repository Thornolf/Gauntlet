/*
** GameObject.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon Jun 12 09:50:42 2017 Thomas Fossaert
*/

#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

# include <iostream>
# include <OgreCamera.h>
# include <OgreEntity.h>
# include <OgreLogManager.h>
# include <OgreRoot.h>
# include <OgreViewport.h>
# include <OgreSceneManager.h>
# include <OgreRenderWindow.h>
# include <OgreConfigFile.h>

# include "GameObject/Character/Script.hpp"
# include "Position.hpp"
# include "Animation.hpp"

class GameObject
{
protected:
  Ogre::AnimationState	*mAnimationState;
  Ogre::Entity		*mEntity;
  Ogre::SceneNode	*mNode;
  Script		*mScript;
  Position		*mPosition;
  Animation		*mAnimation;
  std::string		mNodeName;

public:
  GameObject(int, int, int);
  GameObject(GameObject const &);
  GameObject& operator=(GameObject const &);
  virtual ~GameObject();

  /* Classes */
  Position* getPosition() const;
  void      hide();
  const std::string& getNodeName() const;
  Ogre::Entity* getEntity() const;

  virtual void		setOgreBase(Ogre::SceneManager*) {};
  virtual void		launchScript(Ogre::SceneManager*, Ogre::SceneNode *, const Ogre::FrameEvent&) {};
  virtual void		Animate(const Ogre::FrameEvent&) {};
  virtual void		unsetEntity(Ogre::SceneManager *mSceneMgr) {};
};

#endif
