/*
** Boss.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Wed May 31 11:09:47 2017 Quentin Baudet
*/

#ifndef _Boss_HPP_
#define _Boss_HPP_

#include <iostream>
#include "GameObject/Character/Npc/Npc.hpp"

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
  void takeDamage(int dmg);
  bool isAlive();
  void getDistance();
  int getRange();
};

#endif
