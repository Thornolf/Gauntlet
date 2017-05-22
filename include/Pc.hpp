/*
** Pc.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 15:45:44 2017 Thomas Fossaert
*/

#ifndef _PC_HPP_
#define _PC_HPP_

#include <iostream>
#include "Character.hpp"

class Pc : public Character
{
public:
  Pc(int x, int y, int z);
  Pc(Pc const &);
  Pc& operator=(Pc const &);
  virtual ~Pc();

  /* Classes */

  virtual void getDamage();
  virtual void attack();
  virtual bool isAlive();
  virtual void getDistance();
  virtual size_t getRange();
};

#endif
