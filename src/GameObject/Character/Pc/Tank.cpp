/*
** Tank.cpp for Tank in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 15:37:31 2017 Adrien Warin
** Last update Fri Jun 16 14:47:32 2017 Pierre
*/

#include "GameObject/Character/Pc/Tank.hpp"

Tank::Tank(const std::string &name, int x, int y, int z) : Melee(name, x, y, z)
{
  this->_health = 150;
  this->_attack = 50;
  mPosition = new Position(x, y, z);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[DIE] = new Animation("Death", true, 2);
  this->mAnimation = this->_animations[IDLE];
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
  Ogre::Entity *shield = mSceneMgr->createEntity("item_objectcomponents_shield_shield_1h_alliance_d_01.mesh");
  Ogre::Entity *helm = mSceneMgr->createEntity("item_objectcomponents_head_helm_robe_pvpalliance_c_01_huf.mesh");
  Ogre::Entity *rshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_shoulder_plate_paladinclass_.000.mesh");
  Ogre::Entity *lshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_shoulder_plate_paladinclass_d_01.mesh");


  mEntity = mSceneMgr->createEntity("Tank", "character_human_female_humanfemale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("TankNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  this->mEntity->attachObjectToBone("character/human/female/humanfemale_hd_bone_117", weapon, Ogre::Quaternion(1,1,0,0));
  this->mEntity->attachObjectToBone("character/human/female/humanfemale_hd_bone_55", shield, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/human/female/humanfemale_hd_bone_96", helm, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/human/female/humanfemale_hd_bone_42", rshoulder, Ogre::Quaternion(1,0,0,0));
 this->_aura = new Particle("yellow", "Examples/Aureola" , mSceneMgr, mNode);

}

void Tank::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}

/*void Tank::test()
{
  Ogre::Entity *entity;
  Ogre::SceneNode *node;

  entity = mSceneMgr->createEntity("TankHit" + std::to_string(_id), "cube.mesh");
  this->mEntity->getOrientation()
}
*/
