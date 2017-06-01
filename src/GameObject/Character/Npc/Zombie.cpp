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
  _health = 2;
  _cooldow = 1;
  _speed = 1;
  _alive = true;
  _id = 1;
  _range = 1;
}

Zombie::Zombie(Zombie const & other) : Npc(other)
{
  (void) other;
}

Zombie& Zombie::operator=(Zombie const & other)
{
  (void) other;
  return *this;
}

Zombie::~Zombie()
{

}

void Zombie::getDamage()
{

}

void Zombie::takeDamage(int dmg)
{
  if (this->_health - dmg < 0)
    this->_health = 0;
  else
    this->_health = this->_health - dmg;
}

void Zombie::attack()
{

}

bool Zombie::isAlive()
{
  if (_health <= 0)
    {
      _health = 0;
      return (false);
    }
    return (true);
}

void Zombie::getDistance()
{

}

int Zombie::getRange()
{
  return (_range);
}
