/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Mon May 22 09:51:23 2017 Thomas Fossaert
*/

#include "Zombie.hpp"

Zombie::Zombie()
{
  _health = 2;
  _cooldow = 1;
  _speed = 1;
  _alive = true;
  _id = 1;
  _range = 1;
}

Zombie::Zombie(Zombie const & other)
{
  (void) other;
}

Zombie& Zombie::operator=(Zombie const & other)
{
  (void) other;
  return *this;
}

void Zombie::getDamage()
{

}

void Zombie::attack()
{

}

bool Zombie::isAlive()
{
    return (false);
}

void Zombie::getDistance()
{

}

size_t Zombie::getRange()
{
  return (_range);
}
