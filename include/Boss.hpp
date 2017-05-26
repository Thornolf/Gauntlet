/*
** Boss.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri May 26 12:04:46 2017 Thomas Fossaert
*/

#ifndef _Boss_HPP_
#define _Boss_HPP_

#include <iostream>
#include "Npc.hpp"

class Boss : public Npc
{
public:
  Boss(int x, int y, int z);
  Boss(Boss const &);
  Boss& operator=(Boss const &);
  ~Boss();

  /* Classes */

  void getDamage();
  void attack();
  void takeDamage(size_t dmg);
  bool isAlive();
  void getDistance();
  size_t getRange();
};

#endif
