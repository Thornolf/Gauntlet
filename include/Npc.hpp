/*
** Npc.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 10:00:41 2017 Thomas Fossaert
*/

#ifndef _NPC_HPP_
#define _NPC_HPP_

#include <iostream>
#include "Character.hpp"

class Npc : public Character
{
public:
  Npc();
  Npc(Npc const &);
  Npc& operator=(Npc const &);
  //virtual ~Npc();

  /* Classes */

  virtual void getDamage();
  virtual void attack();
  virtual bool isAlive();
  virtual void getDistance();
  virtual size_t getRange();
};

#endif
