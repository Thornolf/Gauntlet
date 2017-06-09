/*
** Loot.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Fri Jun 09 12:12:13 2017 Thomas Fossaert
*/

#include "GameObject/Loot/Loot.hpp"

Loot::Loot(int x, int y, int z, int id) : GameObject(x, y, z)
{
  this->_id = id;
}

Loot::Loot(Loot const & other) : GameObject(other)
{
  this->_id = other._id;
}

Loot& Loot::operator=(Loot const & other)
{
  this->_id = other._id;
  return *this;
}

Loot::~Loot() {}

bool Loot::isTaken(Pc const & other)
{
  if (this->mPosition == other.getPosition())
    return (true);
  return (false);
}
