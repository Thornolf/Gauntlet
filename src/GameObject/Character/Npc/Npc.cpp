/*
** Npc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Fri May 26 11:51:24 2017 Thomas Fossaert
*/

#include "Npc.hpp"

Npc::Npc(int x, int y, int z) : Character(x, y, z)
{
}

Npc::Npc(Npc const & other) : Character(other)
{
  (void) other;
}

Npc& Npc::operator=(Npc const & other)
{
  (void) other;
  return *this;
}

Npc::~Npc()
{

}

void Npc::getDamage()
{

}

void Npc::takeDamage(size_t dmg)
{
  (void) dmg;
}

void Npc::attack()
{

}

bool Npc::isAlive()
{
    return (false);
}

void Npc::getDistance()
{

}

size_t Npc::getRange()
{
  return (_range);
}
