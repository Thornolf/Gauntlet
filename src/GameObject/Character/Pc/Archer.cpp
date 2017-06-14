/*
** Archer.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
// Last update Tue Jun 13 14:21:44 2017 Thomas Fossaert
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
  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_bow_1h_northrend_c_01.mesh");

  mEntity = mSceneMgr->createEntity("Archer", "character_troll_male_trollmale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("ArcherNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_113", weapon, Ogre::Quaternion(1,0,0,0));
}


void Archer::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}

void Archer::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
