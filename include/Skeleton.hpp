/*
** Skeleton.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri May 26 12:05:03 2017 Thomas Fossaert
*/

#ifndef _Skeleton_HPP_
#define _Skeleton_HPP_

#include <iostream>
#include "Npc.hpp"

class Skeleton : public Npc
{
public:
  Skeleton(int x, int y, int z);
  Skeleton(Skeleton const &);
  Skeleton& operator=(Skeleton const &);
  ~Skeleton();

  /* Classes */

  void getDamage();
  void attack();
  void takeDamage(size_t dmg);
  bool isAlive();
  void getDistance();
  size_t getRange();
};

#endif
