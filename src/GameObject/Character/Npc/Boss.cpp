/*
** Boss.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Sat Jun 10 15:59:51 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Boss.hpp"

Boss::Boss(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 222;
  this->_attack = 100;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "BossNode" + std::to_string(id);
}

Boss::Boss(Boss const & other) : Npc(other)
{
  (void)other;
}

Boss& Boss::operator=(Boss const & other)
{
  (void) other;
  return *this;
}

Boss::~Boss() {}

void Boss::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  //mEntity = mSceneMgr->createEntity("Boss", "character_scourge_male_scourgemale_hd.m2_Geoset_000-Main.mesh");
  mEntity = mSceneMgr->createEntity("Boss" + std::to_string(_id), "creature_northrendghoul2_northrendghoul2.m2_Geoset_000.mesh");

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(100.0f, 100.0f, 100.0f);
  mNode->setOrientation(1,1,0,0);
}

void Boss::launchScript(Ogre::SceneManager *mSceneMgr, Ogre::SceneNode *target, const Ogre::FrameEvent& fe)
{
  mSceneMgr->getSceneNode(mNodeName)->translate(
    mScript->ZombieScript(mSceneMgr->getSceneNode(mNodeName), target) * fe.timeSinceLastFrame,
    Ogre::Node::TS_LOCAL);
  //mPosition->setPosition(nextMove.x, nextMove.y, nextMove.z);
}

void Boss::Animate(const Ogre::FrameEvent& fe)
{
  mAnimationState = mAnimation->simpleAnimation(mAnimationState, "Walk", fe, mEntity);
}

void Boss::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
