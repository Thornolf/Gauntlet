/*
** Loot.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 14:07:02 2017 Thomas Fossaert
*/

#ifndef _LOOT_HPP_
#define _LOOT_HPP_

#include "GameObject.hpp"

class Loot : public GameObject
{
public:
  Loot(int x, int y, int z);
  Loot(Loot const &);
  Loot& operator=(Loot const &);
  virtual ~Loot();

  /* Classes */

  bool isTaken();
};

#endif
