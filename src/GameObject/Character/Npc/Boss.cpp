/*
** Boss.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Tue Jun 13 12:58:46 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Boss.hpp"

Boss::Boss(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 222;
  this->_attack = 100;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "BossNode" + std::to_string(id);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_currentAnimation = this->_animations[IDLE];
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
  mEntity = mSceneMgr->createEntity("Boss" + std::to_string(_id), "creature_zombiefiedvrykul_zombiefiedvrykul.mesh");

  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(1.5f, 1.5f, 1.5f);
}

void Boss::launchScript(Ogre::SceneManager *mSceneMgr, GameObject *target, const Ogre::FrameEvent& fe)
{
  Ogre::Vector3 move = mScript->BossScript(this, target);

  if (move == Ogre::Vector3::ZERO)
  {
    this->launchAnimation(fe, IDLE);
    mAnimationState = this->_currentAnimation->getAnimationState();
  }
  else if (move.x == 1)
  {
    this->launchAnimation(fe, ATTACK);
    mAnimationState = this->_currentAnimation->getAnimationState();
  }
  else
    {
      this->launchAnimation(fe, RUN);
      mAnimationState = this->_currentAnimation->getAnimationState();
      mSceneMgr->getSceneNode(mNodeName)->translate(move * fe.timeSinceLastFrame,Ogre::Node::TS_LOCAL);
    }
}

void Boss::initScript(CollisionTools* tool)
{
  mScript->setCollision(tool, mEntity);
}

void Boss::Animate(const Ogre::FrameEvent& fe)
{
  this->launchAnimation(fe, IDLE);
  mAnimationState = this->_currentAnimation->getAnimationState();
}

void Boss::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
