/*
** Tank.cpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:31 2017 Adrien Warin
** Last update Mon Jun 12 17:23:53 2017 Robin Grattepanche
*/

#include "GameObject/Character/Pc/Tank.hpp"

Tank::Tank(const std::string &name, int x, int y, int z) : Melee(name, x, y, z)
{
  this->_health = 150;
  this->_attack = 50;
  mPosition = new Position(x, y, z);
}

Tank::Tank(Tank const & other) : Melee(other) {}

Tank	&Tank::operator=(Tank const & other)
{
  this->_health = other._health;
  this->_attack = other._attack;
  this->_range = other._range;
  this->_speed = other._speed;
  this->_cooldown = other._cooldown;
  this->mPosition = other.mPosition;
  return (*this);
}

Tank::~Tank() {}

void Tank::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_sword_2h_artifactashbringer_d_01.mesh");

  mEntity = mSceneMgr->createEntity("Tank", "character_human_female_humanfemale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("TankNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  // mNode->setOrientation(1,1,0,0);
  this->mEntity->attachObjectToBone("character/human/female/humanfemale_hd_bone_117", weapon, Ogre::Quaternion(1,1,0,0));
}


void Tank::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Run", fe, mEntity);
}

void Tank::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
