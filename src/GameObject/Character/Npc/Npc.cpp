/*
** Npc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Sat Jun 17 17:55:49 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Npc.hpp"

Npc::Npc(int x, int y, int z, int id) : Character(x, y, z)
{
  this->_id = id;
  this->_hasAttacked = false;
}

Npc::Npc(Npc const & other) : Character(other)
{
  this->_id = other._id;
}

Npc& Npc::operator=(Npc const & other)
{
  this->_id = other._id;
  return *this;
}

Npc::~Npc()
{

}

void Npc::setAttackStatus(bool stat)
{
  this->_hasAttacked = stat;
}

bool Npc::getAttackStatus() const
{
  return (this->_hasAttacked);
}
