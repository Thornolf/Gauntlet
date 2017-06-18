/*
** Boss.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Sat Jun 17 19:55:52 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Boss.hpp"
#include "GameObject/Character/Pc/Pc.hpp"

Boss::Boss(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 222;
  this->_attack = 30;
  this->_speed = 130;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "BossNode" + std::to_string(id);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[DIE] = new Animation("Death", true, 2);
  this->mAnimation = this->_animations[IDLE];
  this->_csound.insert(std::make_pair("ArcherInjured", new Sound("dist/media/soundeffect/Troll/TrollInjured.ogg", "ArcherInjured")));
  this->_csound.insert(std::make_pair("MageInjured", new Sound("dist/media/soundeffect/Human/HumanInjured.ogg", "MageInjured")));
  this->_csound.insert(std::make_pair("TankInjured", new Sound("dist/media/soundeffect/Woman/WomanInjured.ogg", "TankInjured")));
  this->_csound.insert(std::make_pair("WarriorInjured", new Sound("dist/media/soundeffect/Orc/OrcInjured.ogg", "WarriorInjured")));
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

  if (move == Ogre::Vector3::ZERO){
    this->setAnimation(fe, GameObject::IDLE);
    this->setAnimationState();
  }
  else if (move.x == 1 && this->_hasAttacked == false){
    this->setAnimation(fe, GameObject::ATTACK);
    this->setAnimationState();
    this->setAttackStatus(true);
    static_cast<Pc*>(target)->takeDamage(this->_attack);
    this->_csound[static_cast<Pc*>(target)->getName() + "Injured"]->setAudioVolume(30.0);
    this->_csound[static_cast<Pc*>(target)->getName() + "Injured"]->playAudio();
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

void Boss::initScript(CollisionTools* tool)
{
  mScript->setCollision(tool, mEntity);
}

void Boss::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
