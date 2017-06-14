/*
** Skeleton.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Tue Jun 13 14:15:24 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Skeleton.hpp"

Skeleton::Skeleton(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 2;
  this->_attack = 1;
  this->_range = 5;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "SkeletonNode" + std::to_string(id);
}

Skeleton::Skeleton(Skeleton const & other) : Npc(other)
{
  (void)other;
}

Skeleton& Skeleton::operator=(Skeleton const & other)
{
  (void) other;
  return *this;
}

Skeleton::~Skeleton() {}

void Skeleton::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_bow_1h_northrend_c_01.mesh");
  mEntity = mSceneMgr->createEntity("Skeleton" + std::to_string(_id), "character_scourge_male_scourgemale_hd.mesh");

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(1.7f, 1.7f, 1.7f);
  this->mEntity->attachObjectToBone("character/scourge/male/scourgemale_hd_bone_147", weapon, Ogre::Quaternion(1,1,0,0));
}

void Skeleton::launchScript(Ogre::SceneManager *mSceneMgr, Ogre::SceneNode *target, const Ogre::FrameEvent& fe)
{
  mSceneMgr->getSceneNode(mNodeName)->translate(
    mScript->ZombieScript(mSceneMgr->getSceneNode(mNodeName), target) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);
  if (mScript->ZombieScript(mSceneMgr->getSceneNode(mNodeName), target) == Ogre::Vector3::ZERO)
    mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Stand", fe, mEntity);
  else
    mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Run", fe, mEntity);
}

void Skeleton::initScript(CollisionTools* tool)
{
  mScript->setCollision(tool, mEntity);
}

void Skeleton::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}

void Skeleton::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
