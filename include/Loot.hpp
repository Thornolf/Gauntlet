/*
** Loot.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 15:33:46 2017 Thomas Fossaert
*/

#ifndef _LOOT_HPP_
#define _LOOT_HPP_

#include "GameObject.hpp"
#include "Pc.hpp"

class Loot : public GameObject
{
public:
  Loot(int x, int y, int z);
  Loot(Loot const &);
  Loot& operator=(Loot const &);
  virtual ~Loot();

  /* Classes */

  virtual bool isTaken();
};

#endif
