/*
** Boss.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Fri May 26 12:03:44 2017 Thomas Fossaert
*/

#include "Boss.hpp"

Boss::Boss(int x, int y, int z) : Npc(x, y, z)
{
  _health = 10;
  _cooldow = 1;
  _speed = 1;
  _alive = true;
  _id = 1;
  _range = 2;
}

Boss::Boss(Boss const & other) : Npc(other)
{
  (void) other;
}

Boss& Boss::operator=(Boss const & other)
{
  (void) other;
  return *this;
}

Boss::~Boss()
{

}

void Boss::getDamage()
{

}

void Boss::takeDamage(size_t dmg)
{
  if (this->_health - dmg < 0)
    this->_health = 0;
  else
    this->_health = this->_health - dmg;
}

void Boss::attack()
{

}

bool Boss::isAlive()
{
  if (_health <= 0)
    {
      _health = 0;
      return (false);
    }
    return (true);
}

void Boss::getDistance()
{

}

size_t Boss::getRange()
{
  return (_range);
}
