/*
** Boss.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:02:57 2017 baudet_q
*/

#include "Boss.hpp"

Boss::Boss(int x, int y, int z) : Npc(x, y, z)
{
  this->_health = 10;
  this->_range = 2;
  this->_attack = 120;
}

Boss::Boss(Boss const & other) : Npc(other)
{
  (void) other;
}

Boss& Boss::operator=(Boss const & other)
{
  (void) other;
  return *this;
}

Boss::~Boss()
{

}