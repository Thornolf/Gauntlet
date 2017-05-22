/*
** goldStack.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 13:57:43 2017 Thomas Fossaert
*/

#ifndef _GOLDSTACK_HPP_
#define _GOLDSTACK_HPP_

#include "Loot.hpp"

class goldStack : public Loot
{
public:
  goldStack(int x, int y, int z);
  goldStack(goldStack const &);
  goldStack& operator=(goldStack const &);
  ~goldStack();

  /* Classes */

  void increaseScore();
};

#endif
