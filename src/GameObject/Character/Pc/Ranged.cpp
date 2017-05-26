/*
** Ranged.cpp for Ranged in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 10:16:02 2017 Adrien Warin
** Last update Fri May 26 11:52:26 2017 Thomas Fossaert
*/

#include "Ranged.hpp"

Ranged::Ranged (int x, int y, int z) : Pc(x, y, z)
{

}

Ranged::Ranged (Ranged const & other) : Pc(other)
{
(void) other;
}

Ranged& Ranged::operator=(Ranged const & other)
{
    (void) other;
    return (*this);
}

Ranged::~Ranged ()
{

}

void Ranged::getDamage()
{

}

void Ranged::takeDamage(size_t dmg)
{
  (void) dmg;
}

void Ranged::attack()
{

}

bool Ranged::isAlive()
{
    return (false);
}

void Ranged::getDistance()
{

}

size_t Ranged::getRange()
{
    return (_range);
}
