/*
** Archer.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
// Last update Thu Jun 15 11:42:38 2017 Adrien Warin
*/

#include "GameObject/Character/Pc/Archer.hpp"

Archer::Archer(const std::string &name, int x, int y, int z) : Ranged(name, x, y, z)
{
  this->_health = 80;
  this->_attack = 175;
  this->_score = 0;
  mPosition = new Position(x, y, z);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_currentAnimation = this->_animations[IDLE];
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
  Ogre::Entity *lshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_lshoulder_mail_raidhunter_p_01.mesh");
  Ogre::Entity *rshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_rshoulder_mail_raidhunter_p_01.mesh");
  Ogre::Entity *helm = mSceneMgr->createEntity("item_objectcomponents_head_helm_eyepatch_a_01_trm.mesh");
  Ogre::Entity *quiver = mSceneMgr->createEntity("item_objectcomponents_quiver_quiver_vrykulhunter_b_01.mesh");


  mEntity = mSceneMgr->createEntity("Archer", "character_troll_male_trollmale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("ArcherNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
    mNode->setOrientation(-0.7,0,-0.7,0);
  mNode->setPosition(Ogre::Vector3(0, 0, 0));

  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_113", weapon, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_31", lshoulder, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_32", rshoulder, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_44", helm, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_2", quiver, Ogre::Quaternion(1,0,0,1));
  this->_aura = new Particle("Blue", "Examples/AureolaBLEU" , mSceneMgr, mNode);

}


void Archer::Animate(const Ogre::FrameEvent& fe)
{
  this->launchAnimation(fe, IDLE);
  mAnimationState = this->_currentAnimation->getAnimationState();
}

void Archer::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
