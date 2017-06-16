/*
** GameObject.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri Jun 16 10:30:14 2017 Pierre
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

class Script;

class GameObject
{
public:
  enum State
  {
    IDLE,
    STAND,
    RUN,
    WALK,
    ATTACK,
    DIE
  };

protected:
  Ogre::AnimationState	*mAnimationState;
  State _state;
  Animation		*mAnimation;
  Ogre::Entity		*mEntity;
  Ogre::SceneNode	*mNode;
  Script		*mScript;
  Position		*mPosition;
  std::map<State, Animation*>	_animations;
  std::string		mNodeName;
  bool _isBusy;
  State _busyAnimation;

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
  Ogre::SceneNode* getSceneNode() const;
  void setAnimationState();
  void setAnimation(const Ogre::FrameEvent& fe, State state);
  void launchAnimation(const Ogre::FrameEvent& fe, State state);
  bool stillBusy();

  virtual void		setOgreBase(Ogre::SceneManager*) {};
  virtual void		launchScript(Ogre::SceneManager*, GameObject *, const Ogre::FrameEvent&) {};
  virtual void		Animate(const Ogre::FrameEvent&) {};
  virtual void		unsetEntity(Ogre::SceneManager *mSceneMgr) {};
  virtual void    initScript(CollisionTools* tool) {};

};

#endif
