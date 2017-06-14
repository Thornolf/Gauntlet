/*
** Character.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Thu Jun  1 11:30:22 2017 Guillaume CAUCHOIS
*/

#include "GameObject/Character/Character.hpp"

Character::Character(int x, int y, int z) : GameObject(x, y, z)
{
  this->_health = 100;
  this->_cooldown = 100;
  this->_speed = 100;
  /* this->_script = nullptr */
  this->_range = 1;
}

Character::Character(Character const & other) : GameObject(other)
{
  this->_health = other._health;
  this->_cooldown = other._cooldown;
  this->_speed = other._speed;
  /* this->_script = other._script */
  this->_range = other._range;
}

Character& Character::operator=(Character const & other)
{
  this->_health = other._health;
  this->_cooldown = other._cooldown;
  this->_speed = other._speed;
  /* this->_script = other._script */
  this->_range = other._range;
  return *this;
}

Character::~Character() {}

void	Character::takeDamage(int dmg)
{
  this->_health = (this->_health - dmg < 0) ? 0 : this->_health - dmg;
}

void Character::attack(Character *target)
{
  target->takeDamage(this->_attack);
}

bool Character::isAlive()
{
  return ((this->_health > 0));
}

void Character::getDistance() {}

int Character::getRange()
{
  return (this->_range);
}

void Character::launchAnimation(const Ogre::FrameEvent& fe, State state)
{
  if (this->_currentAnimation && (!this->_currentAnimation->isLooping() ||
				  this->_currentAnimation->hasEnded()))
    {
      this->_animations[state]->launch(fe, this->mEntity);
      this->_state = state;
      this->_currentAnimation->disable();
      this->_currentAnimation = this->_animations[state];
      this->_currentAnimation->enable();
    }
}
