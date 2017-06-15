/*
** Skeleton.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Thu Jun 15 08:57:19 2017 Thomas Fossaert
*/

#ifndef _Skeleton_HPP_
#define _Skeleton_HPP_

#include <iostream>
#include "GameObject/Character/Npc/Npc.hpp"

class Skeleton : public Npc
{
public:
  Skeleton(int x, int y, int z, int id);
  Skeleton(Skeleton const &);
  Skeleton& operator=(Skeleton const &);
  ~Skeleton();

  void		setOgreBase(Ogre::SceneManager*);
  void	launchScript(Ogre::SceneManager*, GameObject *, const Ogre::FrameEvent&);
  void		Animate(const Ogre::FrameEvent&);
  void    unsetEntity(Ogre::SceneManager *mSceneMgr);
  void    initScript(CollisionTools* tool);
};

#endif
