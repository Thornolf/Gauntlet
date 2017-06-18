/*
** Archer.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Tue May 30 10:28:05 2017 Pierre
// Last update Sat Jun 17 14:58:07 2017 Thomas Fossaert
*/

#include "GameObject/Character/Pc/Archer.hpp"
#include "RenderManager.hpp"
#include <OgreParticleEmitter.h>

Archer::Archer(const std::string &name, int x, int y, int z) : Ranged(name, x, y, z)
{
  this->_nbrAttack = 0;
  this->_health = 80;
  this->_attack = 175;
  mPosition = new Position(x, y, z);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[DIE] = new Animation("Death", true, 2);
  this->mAnimation = this->_animations[IDLE];
  this->_csound.insert(std::make_pair("Injured", new Sound("dist/media/soundeffect/Troll/TrollInjured.ogg", "Injured")));
  this->_csound.insert(std::make_pair("Weapon", new Sound("dist/media/soundeffect/AttackSound/AttackBowSound.ogg", "Weapon")));
  this->_csound.insert(std::make_pair("GouleInjured", new Sound("dist/media/soundeffect/Goul/GouleInjured.ogg", "GouleInjured")));
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
  mNode->setScale(1.5f, 1.5f, 1.5f);
  mNode->setOrientation(-0.7,0,-0.7,0);

  this->_aura = new Particle("Blue", "Examples/AureolaBLEU" , mSceneMgr, mNode);
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_113", weapon, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_31", lshoulder, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_32", rshoulder, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_44", helm, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/troll/male/trollmale_hd_bone_2", quiver, Ogre::Quaternion(1,0,0,1));

}

void Archer::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}

void Archer::attack(CollisionTools* collision, Ogre::SceneManager* mSceneMgr, RenderManager* render, const Ogre::FrameEvent &fe)
{
  GameObject *tmp;
  Ogre::Entity *entity;
  Ogre::SceneNode *node;
  SCheckCollisionAnswer	collider;

  entity = mSceneMgr->createEntity("ArcherHit", "cube.mesh");
  node = mSceneMgr->getRootSceneNode()->createChildSceneNode("ArcherHitNode", this->mNode->getPosition(), this->mNode->getOrientation());
  node->attachObject(entity);
  node->setScale(9,1,0.9);
  node->translate(Ogre::Vector3(530, 0, 0), Ogre::Node::TS_LOCAL);
  collider = collision->check_ray_collision(node->getPosition(),
					    node->getPosition() + Ogre::Vector3(60.0f, 60.0f, 60.0f), 70.0f, 70.0f, 1,
					    entity, true);
  if (!this->_csound["Weapon"]->getStatus())
  {
    this->_csound["Weapon"]->playAudio();
    this->_unset = new Particle("arrowNumber" + std::to_string(this->_nbrAttack), "Examples/arrow", mSceneMgr, mNode);
    if (collider.collided)
    {
      //if (collider.entity !=)
      if ((tmp = render->searchEntities(collider.entity->getName())))
      {
	if (!collider.entity->getName().compare(0,6, "Zombie") ||
  !collider.entity->getName().compare(0,4, "Boss") ||
  !collider.entity->getName().compare(0, 8, "Skeleton"))
	{
	  static_cast<Npc*>(tmp)->takeDamage(this->_attack);

	  this->_csound["GouleInjured"]->setAudioVolume(35);
	  this->_csound["GouleInjured"]->playAudio();
	  if (static_cast<Npc*>(tmp)->isAlive() == false)
	  {
	    static_cast<Npc*>(tmp)->unsetEntity(mSceneMgr);
	    render->eraseEntities(static_cast<Npc*>(tmp));
	    collision->remove_entity(collider.entity);
	  }
	}
      }
    }
  }
  this->_nbrAttack++;
  mSceneMgr->destroySceneNode(node);
  mSceneMgr->destroyEntity(entity);
}
