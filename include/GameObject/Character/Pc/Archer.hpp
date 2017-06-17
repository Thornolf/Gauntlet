/*
** Archer.hpp for cpp_indie_studio in /home/baudet_q/rendu/CPP/cpp_indie_studio/include/GameObject/Character/Pc
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Jun 12 11:08:04 2017 Quentin Baudet
** Last update Sat Jun 17 10:55:12 2017 Thomas Fossaert
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
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);
  void    attack(CollisionTools *, Ogre::SceneManager*, RenderManager *, const Ogre::FrameEvent &);
  private:
    int		_nbrAttack;
};

#endif
