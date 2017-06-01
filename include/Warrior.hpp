/*
** Warrior.hpp for Warrior in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Fri May 26 17:39:01 2017 Adrien Warin
** Last update Fri May 26 17:40:22 2017 Adrien Warin
*/

#ifndef _WARRIOR_HPP_
#define _WARRIOR_HPP_

#include <iostream>
#include "Melee.hpp"

class Warrior : public Melee
{
public:
  Warrior(const std::string &, int, int, int);
  Warrior(Warrior const &);
  Warrior& operator=(Warrior const &);
  virtual ~Warrior();
};

#endif
