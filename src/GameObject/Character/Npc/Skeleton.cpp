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
#include "GameObject/Character/Pc/Pc.hpp"

Skeleton::Skeleton(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 2;
  this->_attack = 1;
  this->_speed = 75;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "SkeletonNode" + std::to_string(id);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[WALK] = new Animation("Walk", false, 1, 0, 0.5);
  this->_animations[DIE] = new Animation("Death", true, 2);
  this->mAnimation = this->_animations[IDLE];
}

Skeleton::Skeleton(Skeleton const & other) : Npc(other)
{
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

void Skeleton::launchScript(Ogre::SceneManager *mSceneMgr, GameObject *target, const Ogre::FrameEvent& fe)
{
  Ogre::Vector3 move = mScript->SkeletonScript(this, target);

  if (move == Ogre::Vector3::ZERO){
    this->setAnimation(fe, GameObject::IDLE);
    this->setAnimationState();
  }
  else if (move.x == 1 && this->_hasAttacked == false){
    this->setAnimation(fe, GameObject::ATTACK);
    this->setAnimationState();
    this->setAttackStatus(true);
    static_cast<Pc*>(target)->takeDamage(this->_attack);
    if (static_cast<Pc*>(target)->isAlive() == false)
      {
        target->setAnimation(fe, GameObject::DIE);
        target->setAnimationState();
      }
  }
  else
    {
      this->setAnimation(fe, GameObject::RUN);
      this->setAnimationState();
      mSceneMgr->getSceneNode(mNodeName)->translate(move * fe.timeSinceLastFrame);
    }
}

void Skeleton::initScript(CollisionTools* tool)
{
  mScript->setCollision(tool, mEntity);
}

void Skeleton::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
