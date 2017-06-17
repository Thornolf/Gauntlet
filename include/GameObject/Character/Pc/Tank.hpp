/*
** Tank.hpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:25 2017 Adrien Warin
** Last update Sat Jun 17 10:54:11 2017 Thomas Fossaert
*/

#ifndef _TANK_HPP_
#define _TANK_HPP_

#include <iostream>
#include "Melee.hpp"

class Tank : public Melee
{
public:
  Tank(const std::string &, int, int, int);
  Tank(Tank const &);
  Tank&		operator=(Tank const &);
  virtual ~Tank();

  void		setOgreBase(Ogre::SceneManager*);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
  void    attack(CollisionTools *, Ogre::SceneManager*, RenderManager *, const Ogre::FrameEvent &);
};

#endif
