/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:04:02 2017 Quentin Baudet
*/

#include "Zombie.hpp"

Zombie::Zombie(int x, int y, int z) : Npc(x, y, z)
{
  this->_health = 2;
  this->_attack = 1;
}

Zombie::Zombie(Zombie const & other) : Npc(other)
{
  (void)other;
}

Zombie& Zombie::operator=(Zombie const & other)
{
  (void) other;
  return *this;
}

Zombie::~Zombie()
{

}