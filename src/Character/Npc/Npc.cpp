/*
** Npc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Mon May 22 09:54:52 2017 Thomas Fossaert
*/

#include "Npc.hpp"

Npc::Npc()
{
}

Npc::Npc(Npc const & other)
{
  (void) other;
}

Npc& Npc::operator=(Npc const & other)
{
  (void) other;
  return *this;
}

void Npc::getDamage()
{

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
