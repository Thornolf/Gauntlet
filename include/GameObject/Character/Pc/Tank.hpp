/*
** Tank.hpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:25 2017 Adrien Warin
** Last update Mon Jun 12 09:53:19 2017 Thomas Fossaert
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
  void		Animate(const Ogre::FrameEvent&);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif
