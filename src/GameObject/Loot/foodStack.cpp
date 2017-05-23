/*
** foodStack.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Tue May 23 16:12:52 2017 Thomas Fossaert
*/

#include "foodStack.hpp"

foodStack::foodStack(int x, int y, int z) : Loot(x, y, z)
{
}

foodStack::foodStack(foodStack const & other) : Loot(other)
{
  (void) other;
}

foodStack& foodStack::operator=(foodStack const & other)
{
  (void) other;
  return *this;
}

foodStack::~foodStack()
{

}

bool foodStack::isTaken(Pc const & other)
{
  if (this->_position == other.getPosition())
    return (true);
  return (false);
}
