/*
** Warrior.cpp for Warrior
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Fri May 26 17:37:26 2017 Adrien Warin
// Last update Thu Jun 15 10:22:21 2017 Thomas Fossaert
*/

#include "GameObject/Character/Pc/Warrior.hpp"

Warrior::Warrior(const std::string &name, int x, int y, int z) : Melee(name, x, y, z)
{
  this->_health = 120;
  this->_attack = 100;
  mPosition		= new Position(x, y, z);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_currentAnimation = this->_animations[IDLE];
}

Warrior::Warrior(Warrior const & other) : Melee(other) {}

Warrior	&Warrior::operator=(Warrior const & other)
{
  this->_health = other._health;
  this->_attack = other._attack;
  this->_range = other._range;
  this->_speed = other._speed;
  this->_cooldown = other._cooldown;
  this->mPosition = other.mPosition;
  return (*this);
}

Warrior::~Warrior() {}

void Warrior::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_sword_2h_zulaman_d_01.mesh");
  Ogre::Entity *helm = mSceneMgr->createEntity("item_objectcomponents_head_helm_plate_pvpwarrior_d_01_orm.mesh");
  Ogre::Entity *lshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_lshoulder_plate_pvpwarrior_d.000.mesh");
  Ogre::Entity *rshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_rshoulder_plate_pvpwarrior_d_01.mesh");

  mEntity = mSceneMgr->createEntity("Warrior", "character_orc_male_orcmale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("WarriorNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_106", weapon, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_52", helm, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_36", rshoulder, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_29", lshoulder, Ogre::Quaternion(1,0,0,0));

}

void Warrior::Animate(const Ogre::FrameEvent& fe)
{
  this->launchAnimation(fe, RUN);
  mAnimationState = this->_currentAnimation->getAnimationState();
}

void Warrior::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
