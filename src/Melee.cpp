/*
** Melee.cpp for melee in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 11:21:55 2017 Adrien Warin
** Last update Wed May 24 11:54:59 2017 Adrien Warin
*/

#include "Melee.hpp"

Melee::Melee (int x, int y, int z) : Pc(x, y, z)
{

}

Melee::Melee(Melee const & other) : Pc(other)
{
    (void) other;
}

Melee& Melee::operator=(Melee const & other)
{
    (void) other;
    return(*this);
}

Melee::~Melee ()
{

}

void Melee::getDamage()
{

}

void Melee::attack()
{

}

bool Melee::isAlive()
{
    return (false);
}

void Melee::getDistance()
{

}

size_t Melee::getRange()
{
    return (_range);
}
