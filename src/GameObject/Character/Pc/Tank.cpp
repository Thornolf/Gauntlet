/*
** Tank.cpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:31 2017 Adrien Warin
** Last update Fri Jun 09 12:18:26 2017 Thomas Fossaert
*/

#include "GameObject/Character/Pc/Tank.hpp"

Tank::Tank(const std::string &name, int x, int y, int z) : Melee(name, x, y, z)
{
  this->_health = 150;
  this->_attack = 50;
}

Tank::Tank(Tank const & other) : Melee(other) {}

Tank	&Tank::operator=(Tank const & other)
{
  this->_health = other._health;
  this->_attack = other._attack;
  this->_range = other._range;
  this->_speed = other._speed;
  this->_cooldown = other._cooldown;
  this->mPosition = other.mPosition;
  return (*this);
}

Tank::~Tank() {}
