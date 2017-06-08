/*
** Boss.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Thu Jun 08 08:59:08 2017 fossae_t
*/

#ifndef _Boss_HPP_
#define _Boss_HPP_

#include <iostream>
#include "GameObject/Character/Npc/Npc.hpp"

class Boss : public Npc
{
public:
  Boss(int x, int y, int z, int id);
  Boss(Boss const &);
  Boss& operator=(Boss const &);
  ~Boss();

  /* Classes */

  void		setOgreBase(Ogre::SceneManager*);
  Ogre::Vector3	launchScript(Ogre::SceneManager*, Ogre::SceneNode *);
  void		Animate(const Ogre::FrameEvent&);
  void    unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif
