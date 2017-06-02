/*
** Skeleton.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:03:51 2017 Quentin Baudet
*/

#include "Skeleton.hpp"

Skeleton::Skeleton(int x, int y, int z) : Npc(x, y, z)
{
  this->_health = 1;
  this->_range = 5;
  this->_attack = -2;
}

Skeleton::Skeleton(Skeleton const & other) : Npc(other)
{
  (void) other;
}

Skeleton& Skeleton::operator=(Skeleton const & other)
{
  (void) other;
  return *this;
}

Skeleton::~Skeleton()
{

}