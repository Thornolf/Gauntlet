/*
** Warrior.cpp for Warrior in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src/GameObject/Character/Melee
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Fri May 26 17:37:26 2017 Adrien Warin
** Last update Fri May 26 17:51:01 2017 Adrien Warin
*/

#include "Warrior.hpp"

Warrior::Warrior(size_t x, size_t y, size_t z) : Melee(x, y, z)
{
  _health = 120;
  _attack = 100;
  _cooldow = 1;
  _speed = 1;
  _alive = true;
  _id = 1;
  _range = 1;
}

Warrior::Warrior(Warrior const & other) : Melee(other)
{
  (void) other;
}

Warrior& Warrior::operator=(Warrior const & other)
{
  (void) other;
  return *this;
}

Warrior::~Warrior()
{

}

void Warrior::takeDamage(size_t dmg)
{
  if (this->_health - dmg < 0)
    this->_health = 0;
  else
    this->_health = this->_health - dmg;
}

void Warrior::attack()
{

}

bool Warrior::isAlive()
{
  if (_health <= 0)
    {
      _health = 0;
      return (false);
    }
    return (true);
}

void Warrior::getDistance()
{

}

size_t Warrior::getRange()
{
  return (_range);
}
