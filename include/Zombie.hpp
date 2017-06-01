/*
** Zombie.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Thu Jun 01 08:49:28 2017 Thomas Fossaert
*/

#ifndef _Zombie_HPP_
#define _Zombie_HPP_

#include <OgreCamera.h>
#include <OgreEntity.h>
#include <OgreLogManager.h>
#include <OgreRoot.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>

#include <iostream>
#include "Script.hpp"
#include "Position.hpp"
#include "Animation.hpp"
#include "Npc.hpp"

class Zombie : public Npc
{
  private:
    Ogre::AnimationState *mAnimationState;
    Ogre::Entity *mEntity;
    Ogre::SceneNode *mNode;
    Script *mScript;
    Position *mPosition;
    Animation *mAnimation;
  public:
    Zombie(int x, int y, int z);
    Zombie(Zombie const &);
    Zombie& operator=(Zombie const &);
    ~Zombie();

    /* Classes */

    void setOgreBase(Ogre::SceneManager*);
    Ogre::Vector3 launchScript(Ogre::SceneNode *);
    void Animate(const Ogre::FrameEvent&);

    void getDamage();
    void attack();
    void takeDamage(int dmg);
    bool isAlive();
    void getDistance();
    int getRange();
};

#endif
