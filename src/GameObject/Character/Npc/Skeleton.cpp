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
  _health = 1;
  _cooldow = 1;
  _speed = 1;
  _alive = true;
  _id = 1;
  _range = 5;
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

void Skeleton::getDamage()
{

}

void Skeleton::takeDamage(int dmg)
{
  if (this->_health - dmg < 0)
    this->_health = 0;
  else
    this->_health = this->_health - dmg;
}

void Skeleton::attack()
{

}

bool Skeleton::isAlive()
{
  if (_health <= 0)
    {
      _health = 0;
      return (false);
    }
    return (true);
}

void Skeleton::getDistance()
{

}

int Skeleton::getRange()
{
  return (_range);
}
