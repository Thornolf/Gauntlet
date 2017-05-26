/*
** Zombie.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri May 26 11:47:44 2017 Thomas Fossaert
*/

#ifndef _Zombie_HPP_
#define _Zombie_HPP_

#include <iostream>
#include "Npc.hpp"

class Zombie : public Npc
{
public:
  Zombie(int x, int y, int z);
  Zombie(Zombie const &);
  Zombie& operator=(Zombie const &);
  ~Zombie();

  /* Classes */

  void getDamage();
  void attack();
  void takeDamage(size_t dmg);
  bool isAlive();
  void getDistance();
  size_t getRange();
};

#endif