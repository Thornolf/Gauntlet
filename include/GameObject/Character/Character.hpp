/*
** Character.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Wed May 31 11:02:36 2017 Quentin Baudet
*/

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <iostream>
#include "GameObject/GameObject.hpp"

class Character : public GameObject
{
  protected:
  int		_health;
  int		_attack;
  int		_cooldown;
  int		_speed;
  /*Script    *_script <---------- décommenter après la classe Script*/
  int		_range;

public:
  Character(int x, int y, int z);
  Character(Character const &);
  Character& operator=(Character const &);
  virtual ~Character();

  /* Classes */

  void takeDamage(int dmg);
  void attack(Character *target);
  bool isAlive();
  void getDistance();
  int getRange();
};

#endif
