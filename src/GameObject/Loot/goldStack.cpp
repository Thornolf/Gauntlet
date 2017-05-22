/*
** goldStack.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Mon May 22 14:10:21 2017 Thomas Fossaert
*/

#include "goldStack.hpp"

goldStack::goldStack(int x, int y, int z) : Loot(x, y, z)
{
}

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
