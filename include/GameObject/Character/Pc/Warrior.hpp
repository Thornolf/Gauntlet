/*
** Warrior.hpp for Warrior in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Fri May 26 17:39:01 2017 Adrien Warin
** Last update Tue Jun 13 12:28:25 2017 Thomas Fossaert
*/

#ifndef		_WARRIOR__HPP_
#define		_WARRIOR__HPP_

#include <iostream>
#include "Melee.hpp"

class Warrior : public Melee
{
public:
  Warrior(const std::string &, int, int, int);
  Warrior(Warrior const &);
  Warrior& operator=(Warrior const &);
  virtual ~Warrior();

  void		setOgreBase(Ogre::SceneManager*);
  void		Animate(const Ogre::FrameEvent&);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif		/* !_WARRIOR__HPP_ */
