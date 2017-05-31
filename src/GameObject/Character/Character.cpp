/*
** Character.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:03:08 2017 Quentin Baudet
*/

#include "Character.hpp"

Character::Character(int x, int y, int z) : GameObject(x, y, z)
{
}

Character::Character(Character const & other) : GameObject(other)
{
  (void) other;
}

Character& Character::operator=(Character const & other)
{
  (void) other;
  return *this;
}

Character::~Character()
{

}

void Character::takeDamage(int dmg)
{
  (void) dmg;
}

void Character::attack()
{

}

bool Character::isAlive()
{
    return (false);
}

void Character::getDistance()
{

}

int Character::getRange()
{
  return (_range);
}
