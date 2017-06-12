/*
** Mage.hpp for cpp_indie_studio in /home/baudet_q/rendu/CPP/cpp_indie_studio/include/GameObject/Character/Pc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Jun 12 11:08:04 2017 Quentin Baudet
** Last update Mon Jun 12 11:10:06 2017 Quentin Baudet
*/

#ifndef _MAGE_HPP_
#define _MAGE_HPP_

#include <iostream>
#include "Ranged.hpp"

class Mage : public Ranged
{
public:
  Mage(const std::string &, int, int, int);
  Mage(Mage const &);
  Mage&		operator=(Mage const &);
  virtual ~Mage();

  void		setOgreBase(Ogre::SceneManager*);
  void		Animate(const Ogre::FrameEvent&);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif
