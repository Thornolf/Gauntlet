/*
** Warrior.cpp for Warrior
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Fri May 26 17:37:26 2017 Adrien Warin
** Last update Fri May 26 17:51:01 2017 Adrien Warin
*/

#include "GameObject/Character/Pc/Warrior.hpp"

Warrior::Warrior(const std::string &name, int x, int y, int z) : Melee(name, x, y, z)
{
  this->_health = 120;
  this->_attack = 100;
}

Warrior::Warrior(Warrior const & other) : Melee(other)
{
  (void)other;
}

Warrior& Warrior::operator=(Warrior const & other)
{
  (void)other;
  return *this;
}

Warrior::~Warrior() {}