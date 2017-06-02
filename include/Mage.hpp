/*
** Mage.hpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/include
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:26:19 2017 Pierre
** Last update Tue May 30 10:39:47 2017 Pierre
*/

#ifndef _MAGE_HPP_
#define _MAGE_HPP_

#include <iostream>
#include "Pc.hpp"

class Mage : public Ranged
{
public:
  Mage(int x, int y, int z);
  Mage(Mage const &);
  Mage& operator=(Mage const &);
  virtual ~Mage();

  /* Classes */

  virtual void getDamage();
  virtual void attack();
  virtual bool isAlive();
  virtual void getDistance();
  virtual size_t getRange();
};

#endif
