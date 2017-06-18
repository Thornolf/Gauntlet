/*
** Character.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Sat Jun 17 19:53:05 2017 Thomas Fossaert
*/

#include "GameObject/Character/Character.hpp"

Character::Character(int x, int y, int z) : GameObject(x, y, z)
{
  this->_health = 100;
  this->_cooldown = 100;
  this->_speed = 350;
  /* this->_script = nullptr */
  this->_range = 1;
  this->_injuredSound.insert(std::make_pair("GouleInjured", new Sound("dist/media/soundeffect/Goul/GouleInjured.ogg", "GouleInjured")));
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
  std::cout << _health << '\n';
  this->_health = (this->_health - dmg < 0) ? 0 : this->_health - dmg;
}

bool Character::isAlive() const
{
  if (this->_health > 0)
    return true;
  return (false);
}

void Character::getDistance() const {}

int Character::getRange() const
{
  return (this->_range);
}

void Character::launchAnimation(const Ogre::FrameEvent& fe, State state)
{
  if (this->mAnimation && (!this->mAnimation->isLooping() ||
				  this->mAnimation->hasEnded()))
    {
      this->_animations[state]->launch(fe, this->mEntity);
      this->_state = state;
      this->mAnimation->disable();
      this->mAnimation = this->_animations[state];
      this->mAnimation->enable();
    }
}

void Character::gainHealth(int value)
{
  this->_health += value;
  if (this->_health > 300)
    this->_health = 300;
}

void Character::Animate(const Ogre::FrameEvent& fe)
{
  this->setAnimation(fe, GameObject::IDLE);
  this->setAnimationState();
}

