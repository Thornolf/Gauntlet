/*
** goldStack.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Tue May 23 16:12:46 2017 Thomas Fossaert
*/

#include "GameObject/Loot/goldStack.hpp"

goldStack::goldStack(int x, int y, int z, int id) : Loot(x, y, z, id) {}

goldStack::goldStack(goldStack const & other) : Loot(other)
{
  (void) other;
}

goldStack& goldStack::operator=(goldStack const & other)
{
  (void) other;
  return *this;
}

goldStack::~goldStack()
{

}

bool goldStack::isTaken(Pc const & other)
{
  if (this->_position == other.getPosition())
    return (true);
  return (false);
}
