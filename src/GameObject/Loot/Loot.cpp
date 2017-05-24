/*
** Loot.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Tue May 23 16:12:39 2017 Thomas Fossaert
*/

#include "Loot.hpp"

Loot::Loot(int x, int y, int z) : GameObject(x, y, z)
{
}

Loot::Loot(Loot const & other) : GameObject(other)
{
  (void) other;
}

Loot& Loot::operator=(Loot const & other)
{
  (void) other;
  return *this;
}

Loot::~Loot()
{

}

bool Loot::isTaken(Pc const & other)
{
  if (this->_position == other.getPosition())
    return (true);
  return (false);
}
