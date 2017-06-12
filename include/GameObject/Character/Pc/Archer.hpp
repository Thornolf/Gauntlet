/*
** Archer.hpp for cpp_indie_studio in /home/baudet_q/rendu/CPP/cpp_indie_studio/include/GameObject/Character/Pc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Jun 12 11:08:04 2017 Quentin Baudet
** Last update Mon Jun 12 11:19:51 2017 Quentin Baudet
*/

#ifndef _ARCHER_HPP_
#define _ARCHER_HPP_

# include <iostream>
# include "Ranged.hpp"

class Archer : public Ranged
{
public:
  Archer(const std::string &, int, int, int);
  Archer(Archer const &);
  Archer&		operator=(Archer const &);
  virtual ~Archer();

  void		setOgreBase(Ogre::SceneManager*);
  void		Animate(const Ogre::FrameEvent&);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
};

#endif
