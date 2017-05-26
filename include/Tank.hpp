/*
** Tank.hpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:25 2017 Adrien Warin
** Last update Wed May 24 15:51:16 2017 Adrien Warin
*/

#ifndef _TANK_HPP_
#define _TANK_HPP_

#include <iostream>
#include "Melee.hpp"

class Tank : public Melee
{
private:
    int _hp;
    int _attack;

public:
  Tank(int, int, int);
  Tank(Tank const &);
  Tank& operator=(Tank const &);
  virtual ~Tank();

  /* Classes */

  virtual void getDamage();
  virtual void attack();
  virtual bool isAlive();
  virtual void getDistance();
  virtual size_t getRange();
};

#endif
