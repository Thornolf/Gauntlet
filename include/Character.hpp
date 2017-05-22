/*
** Character.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Mon May 22 10:00:26 2017 Thomas Fossaert
*/

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <iostream>

class Character
{
  protected:
  size_t    _health;
  size_t    _cooldow;
  size_t    _speed;
  /*Script    *_script <---------- décommenter après la classe Script*/
  /*Position  *_possition <------- décommenter après la Classe position*/
  bool   _alive;
  int    _id;
  size_t _range;

public:
  Character();
  Character(Character const &);
  Character& operator=(Character const &);
  //virtual ~Character();

  /* Classes */

  virtual void getDamage();
  virtual void attack();
  virtual bool isAlive();
  virtual void getDistance();
  virtual size_t getRange();
};

#endif
