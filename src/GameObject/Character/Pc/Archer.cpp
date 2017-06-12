/*
** Archer.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
** Last update Mon Jun 12 11:23:52 2017 Quentin Baudet
*/

#include "GameObject/Character/Pc/Archer.hpp"

Archer::Archer(const std::string &name, int x, int y, int z) : Ranged(name, x, y, z)
{
  this->_health = 80;
  this->_attack = 175;
  mPosition = new Position(x, y, z);
}

Archer::Archer(Archer const & other) : Ranged(other) {}

Archer	&Archer::operator=(Archer const & other)
{
  this->_health = other._health;
  this->_attack = other._attack;
  this->_range = other._range;
  this->_speed = other._speed;
  this->_cooldown = other._cooldown;
  this->mPosition = other.mPosition;
  return (*this);
}

Archer::~Archer() {}

void Archer::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  Ogre::Entity *weapon = mSceneMgr->createEntity("WEAPONARCHER.mesh");

  mEntity = mSceneMgr->createEntity("Archer", "MESHARCHER.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("ArcherNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  mNode->setOrientation(1,1,0,0);
  this->mEntity->attachObjectToBone("BONES/ARCHER", weapon, Ogre::Quaternion(1,1,0,0));
}


void Archer::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Run", fe, mEntity);
}

void Archer::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
