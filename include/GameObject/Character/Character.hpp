/*
** Character.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon Jun 05 14:35:41 2017 Thomas Fossaert
*/

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <iostream>
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
#include "GameObject/GameObject.hpp"

class Character : public GameObject
{
  protected:
  int		_health;
  int		_attack;
  int		_cooldown;
  int		_speed;
  int		_range;

  Ogre::AnimationState	*mAnimationState;
  Ogre::Entity		      *mEntity;
  Ogre::SceneNode       *mNode;
  Script                *mScript;
  Position              *mPosition;
  Animation             *mAnimation;
  std::string           mNodeName;

public:
  Character(int x, int y, int z);
  Character(Character const &);
  Character& operator=(Character const &);
  virtual ~Character();

  /* Classes */

  void takeDamage(int dmg);
  void attack(Character *target);
  bool isAlive();
  void getDistance();
  int getRange();

  /*virtual void		setOgreBase(Ogre::SceneManager*);
  virtual Ogre::Vector3	launchScript(Ogre::SceneNode *);
  virtual void		Animate(const Ogre::FrameEvent&);*/
};

#endif
