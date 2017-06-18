/*
** Melee.cpp for melee in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 11:21:55 2017 Adrien Warin
** Last update Fri May 26 16:40:51 2017 Adrien Warin
*/

#include "GameObject/Character/Pc/Melee.hpp"

Melee::Melee (const std::string &name, int x, int y, int z) : Pc(name, x, y, z)
{

}

Melee::Melee(Melee const & other) : Pc(other)
{
}

Melee& Melee::operator=(Melee const &)
{
  return(*this);
}

Melee::~Melee ()
{

}