/*
** Npc.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Thu Jun 08 16:09:28 2017 Thomas Fossaert
*/

#ifndef _NPC_HPP_
#define _NPC_HPP_

#include <iostream>
#include "GameObject/Character/Character.hpp"

class Npc : public Character
{
protected:
  int _id;
public:
  Npc(int x, int y, int z, int id);
  Npc(Npc const &);
  Npc& operator=(Npc const &);
  virtual ~Npc();

  virtual void		setOgreBase(Ogre::SceneManager*);
  virtual Ogre::Vector3	launchScript(Ogre::SceneManager*, Ogre::SceneNode *);
  virtual void		Animate(const Ogre::FrameEvent&);
  virtual void    unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif
