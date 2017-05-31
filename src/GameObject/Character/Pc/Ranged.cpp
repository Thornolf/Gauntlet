/*
** Ranged.cpp for Ranged in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 10:16:02 2017 Adrien Warin
** Last update Wed May 31 11:04:25 2017 Quentin Baudet
*/

#include "Ranged.hpp"

Ranged::Ranged (int newX, int newY, int newZ) : Pc(newX, newY, newZ)
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

void Ranged::takeDamage(int dmg)
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

int Ranged::getRange()
{
    return (_range);
}
