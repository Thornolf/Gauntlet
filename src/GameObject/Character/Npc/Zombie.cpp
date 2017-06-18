/*
** Zombie.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Sun Jun 18 16:56:49 2017 Thomas Fossaert
*/

#include "GameObject/Character/Npc/Zombie.hpp"
#include "GameObject/Character/Pc/Pc.hpp"

Zombie::Zombie(int x, int y, int z, int id) : Npc(x, y, z, id)
{
  this->_health = 2;
  this->_attack = 1;
  this->_speed = 200;
  mPosition = new Position(x, y, z);
  mScript = new Script();
  mNodeName = "ZombieNode" + std::to_string(id);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[WALK] = new Animation("Walk", false, 1, 0, 0.5);
  this->_animations[DIE] = new Animation("Death", true, 2);
  this->mAnimation = this->_animations[RUN];
  this->_csound.insert(std::make_pair("ArcherInjured", new Sound("dist/media/soundeffect/Troll/TrollInjured.ogg", "ArcherInjured")));
  this->_csound.insert(std::make_pair("MageInjured", new Sound("dist/media/soundeffect/Human/HumanInjured.ogg", "MageInjured")));
  this->_csound.insert(std::make_pair("TankInjured", new Sound("dist/media/soundeffect/Woman/WomanInjured.ogg", "TankInjured")));
  this->_csound.insert(std::make_pair("WarriorInjured", new Sound("dist/media/soundeffect/Orc/OrcInjured.ogg", "WarriorInjured")));
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
  mEntity = mSceneMgr->createEntity("Zombie" + std::to_string(_id), "creature_northrendghoul2_northrendghoul2.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(1.7f, 1.7f, 1.7f);
}

void Zombie::launchScript(Ogre::SceneManager *mSceneMgr, GameObject *target, const Ogre::FrameEvent& fe)
{
  Ogre::Vector3 move = mScript->ZombieScript(this, target);

  if (move == Ogre::Vector3::ZERO){
    this->setAnimation(fe, GameObject::IDLE);
    this->setAnimationState();
  }
  else if (move.x == 1 && this->_hasAttacked == false){
    this->setAnimation(fe, GameObject::ATTACK);
    this->setAnimationState();
    this->setAttackStatus(true);
    this->_csound[static_cast<Pc*>(target)->getName() + "Injured"]->setAudioVolume(30.0);
    this->_csound[static_cast<Pc*>(target)->getName() + "Injured"]->playAudio();
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
      mSceneMgr->getSceneNode(mNodeName)->translate(move * fe.timeSinceLastFrame, Ogre::Node::TS_PARENT);
    }
}

void Zombie::initScript(CollisionTools* tool)
{
  mScript->setCollision(tool, mEntity);
}

void Zombie::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}
