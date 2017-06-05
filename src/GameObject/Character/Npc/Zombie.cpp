/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Thu Jun  1 11:29:39 2017 Guillaume CAUCHOIS
*/

#include "GameObject/Character/Npc/Zombie.hpp"

Zombie::Zombie(int x, int y, int z, int id) : Npc(x, y, z)
{
  this->_id = id;
  this->_health = 2;
  this->_attack = 1;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "ZombieNode" + std::to_string(id);
}

Zombie::Zombie(Zombie const & other) : Npc(other)
{
  (void)other;
}

Zombie& Zombie::operator=(Zombie const & other)
{
  (void) other;
  return *this;
}

Zombie::~Zombie() {}

void Zombie::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  //mEntity = mSceneMgr->createEntity("Zombie", "character_scourge_male_scourgemale_hd.m2_Geoset_000-Main.mesh");
  mEntity = mSceneMgr->createEntity("Zombie" + std::to_string(_id), "creature_northrendghoul2_northrendghoul2.m2_Geoset_000.mesh");

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(100.0f, 100.0f, 100.0f);
  mNode->setOrientation(1,1,0,0);
}

Ogre::Vector3 Zombie::launchScript(Ogre::SceneManager *mSceneMgr, Ogre::SceneNode *target)
{
  Ogre::Vector3 nextMove = Ogre::Vector3::ZERO;
  nextMove = mScript->ZombieScript(mSceneMgr->getSceneNode("ZombieNode1"), target);
  //mPosition->setPosition(nextMove.x, nextMove.y, nextMove.z);
  return (nextMove);
}

void Zombie::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}
