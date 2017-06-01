/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Thu Jun 01 09:42:33 2017 Thomas Fossaert
*/

#include "Zombie.hpp"

Zombie::Zombie(int x, int y, int z) : Npc(x, y, z)
{
  _health = 2;
  _cooldow = 1;
  _speed = 1;
  _alive = true;
  _id = 1;
  _range = 1;
  mPosition = new Position(x, y, z);
  mScript = new Script();
}

Zombie::Zombie(Zombie const & other) : Npc(other)
{
  (void) other;
}

Zombie& Zombie::operator=(Zombie const & other)
{
  (void) other;
  return *this;
}

Zombie::~Zombie()
{

}

void Zombie::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  mEntity = mSceneMgr->createEntity("Zombie", "robot.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("ZombieNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(1.0f, 1.0f, 1.0f);
}

Ogre::Vector3 Zombie::launchScript(Ogre::SceneNode *target)
{
  Ogre::Vector3 nextMove = Ogre::Vector3::ZERO;
  nextMove = mScript->ZombieScript(mNode, target);
  //mPosition->setPosition(nextMove.x, nextMove.y, nextMove.z);
  return (nextMove);
}

void Zombie::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}

void Zombie::getDamage()
{

}

void Zombie::takeDamage(int dmg)
{
  if (this->_health - dmg < 0)
    this->_health = 0;
  else
    this->_health = this->_health - dmg;
}

void Zombie::attack()
{

}

bool Zombie::isAlive()
{
  if (_health <= 0)
    {
      _health = 0;
      return (false);
    }
    return (true);
}

void Zombie::getDistance()
{

}

int Zombie::getRange()
{
  return (_range);
}
