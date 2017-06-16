#include <OIS.h>

/*
** Mage.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
** Last update Fri Jun 16 14:34:53 2017 Pierre
*/

#include "GameObject/Character/Pc/Mage.hpp"

Mage::Mage(const std::string &name, int x, int y, int z) : Ranged(name, x, y, z)
{
  this->_health			= 80;
  this->_attack			= 175;
  mPosition			= new Position(x, y, z);
  this->_animations[IDLE]	= new Animation("Stand", false);
  this->_animations[RUN]	= new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK]	= new Animation("Spell", false, 1, 0, 0.5);
  this->_animations[DIE]	= new Animation("Death", true, 2);
  this->mAnimation = this->_animations[IDLE];
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
  Ogre::Entity *lshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_lshoulder_robe_raidmage_e_01.mesh");
  Ogre::Entity *rshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_rshoulder_robe_raidmage_e_01.mesh");
  Ogre::Entity *helm = mSceneMgr->createEntity("item_objectcomponents_head_helm_robe_raidmage_e_01_hum.mesh");

  mEntity = mSceneMgr->createEntity("Mage", "character_human_male_humanmale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("MageNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  mNode->setOrientation(-0.7,0,-0.7,0);
  this->mEntity->attachObjectToBone("character/human/male/humanmale_hd_bone_115", weapon, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/human/male/humanmale_hd_bone_33", lshoulder, Ogre::Quaternion(0,0,1,0));
  this->mEntity->attachObjectToBone("character/human/male/humanmale_hd_bone_32", rshoulder, Ogre::Quaternion(0,0,1,0));
  this->mEntity->attachObjectToBone("character/human/male/humanmale_hd_bone_93", helm, Ogre::Quaternion(1,0,0,0));
  this->_aura = new Particle("RED", "Examples/AureolaROUGE", mSceneMgr, mNode);

}

void Mage::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(this->mEntity);
}
