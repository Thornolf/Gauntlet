/*
** Pc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:04:17 2017 Quentin Baudet
*/

#include "Pc.hpp"

Pc::Pc(int x, int y, int z) : Character(x, y, z)
{
}

Pc::Pc(Pc const & other) : Character(other)
{
  (void) other;
}

Pc& Pc::operator=(Pc const & other)
{
  (void) other;
  return *this;
}

Pc::~Pc()
{

}

void Pc::attack()
{

}

void Pc::takeDamage(int dmg)
{
  (void) dmg;
}

bool Pc::isAlive()
{
    return (false);
}

void Pc::getDistance()
{

}

int Pc::getRange()
{
  return (_range);
}
