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
private:
    size_t    _health;
    size_t    _cooldow;
    size_t    _speed;
    size_t   _attack;
    /*Script    *_script <---------- décommenter après la classe Script*/
    /*Position  *_possition <------- décommenter après la Classe position*/
    bool   _alive;
    int    _id;
    size_t _range;

public:
  Warrior(size_t, size_t, size_t);
  Warrior(Warrior const &);
  Warrior& operator=(Warrior const &);
  virtual ~Warrior();

  /* Classes */
  virtual void takeDamage(size_t dmg);
  virtual void attack();
  virtual bool isAlive();
  virtual void getDistance();
  virtual size_t getRange();
};

#endif
