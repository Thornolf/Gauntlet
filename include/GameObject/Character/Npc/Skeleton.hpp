/*
** Skeleton.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Wed May 31 11:08:11 2017 Quentin Baudet
*/

#ifndef _Skeleton_HPP_
#define _Skeleton_HPP_

#include <iostream>
#include "GameObject/Character/Npc/Npc.hpp"

class Skeleton : public Npc
{
public:
  Skeleton(int x, int y, int z);
  Skeleton(Skeleton const &);
  Skeleton& operator=(Skeleton const &);
  ~Skeleton();
};

#endif
