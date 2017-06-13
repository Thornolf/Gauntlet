/*
** Mage.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
** Last update Tue Jun 13 13:07:52 2017 Thomas Fossaert
*/

#include "GameObject/Character/Pc/Mage.hpp"

Mage::Mage(const std::string &name, int x, int y, int z) : Ranged(name, x, y, z)
{
  this->_health		= 80;
  this->_attack		= 175;
  mPosition		= new Position(x, y, z);
}

Mage::Mage(Mage const & other) : Ranged(other) {}

Mage	&Mage::operator=(Mage const & other)
{
  this->_health = other._health;
  this->_attack = other._attack;
  this->_range = other._range;
  this->_speed = other._speed;
  this->_cooldown = other._cooldown;
  this->mPosition = other.mPosition;
  return (*this);
}

Mage::~Mage() {}

void Mage::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_staff_2h_demonweapon_c_01.mesh");

  mEntity = mSceneMgr->createEntity("Mage", "character_human_male_humanmale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("MageNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  this->mEntity->attachObjectToBone("character/human/male/humanmale_hd_bone_117", weapon, Ogre::Quaternion(1,1,0,0));
}


void Mage::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Run", fe, mEntity);
}

void Mage::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(this->mEntity);
}
