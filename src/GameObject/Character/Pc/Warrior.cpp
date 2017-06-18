/*
** Warrior.cpp for Warrior
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Fri May 26 17:37:26 2017 Adrien Warin
// Last update Sun Jun 18 16:11:57 2017 Thomas Fossaert
*/

#include "GameObject/Character/Pc/Warrior.hpp"
#include "RenderManager.hpp"

Warrior::Warrior(const std::string &name, int x, int y, int z) : Melee(name, x, y, z)
{
  this->_health = 120;
  this->_attack = 100;
  mPosition		= new Position(x, y, z);
  this->_animations[IDLE] = new Animation("Stand", false);
  this->_animations[RUN] = new Animation("Run", false, this->_speed, 125);
  this->_animations[ATTACK] = new Animation("Attack", false, 1, 0, 0.5);
  this->_animations[DIE] = new Animation("Death", true, 2);
  this->mAnimation = this->_animations[IDLE];
  this->_csound.insert(std::make_pair("Injured", new Sound("dist/media/soundeffect/Orc/OrcInjured.ogg", "Injured")));
  this->_csound.insert(std::make_pair("Weapon", new Sound("dist/media/soundeffect/AttackSound/SwordFleshHit2.ogg", "Weapon")));
  this->_csound.insert(std::make_pair("GouleInjured", new Sound("dist/media/soundeffect/Goul/GouleInjured.ogg", "GouleInjured")));
}

Warrior::Warrior(Warrior const & other) : Melee(other) {}

Warrior	&Warrior::operator=(Warrior const & other)
{
  this->_health = other._health;
  this->_attack = other._attack;
  this->_range = other._range;
  this->_speed = other._speed;
  this->_cooldown = other._cooldown;
  this->mPosition = other.mPosition;
  return (*this);
}

Warrior::~Warrior() {}

void Warrior::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  Ogre::Entity *weapon = mSceneMgr->createEntity("item_objectcomponents_weapon_sword_2h_zulaman_d_01.mesh");
  Ogre::Entity *helm = mSceneMgr->createEntity("item_objectcomponents_head_helm_plate_pvpwarrior_d_01_orm.mesh");
  Ogre::Entity *lshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_lshoulder_plate_pvpwarrior_d.000.mesh");
  Ogre::Entity *rshoulder = mSceneMgr->createEntity("item_objectcomponents_shoulder_rshoulder_plate_pvpwarrior_d_01.mesh");

  mEntity = mSceneMgr->createEntity("Warrior", "character_orc_male_orcmale_hd.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("WarriorNode", mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(2.0f, 2.0f, 2.0f);
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_106", weapon, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_52", helm, Ogre::Quaternion(1,0,0,0));
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_36", rshoulder, Ogre::Quaternion(1,-0.5,0,0));
  this->mEntity->attachObjectToBone("character/orc/male/orcmale_hd_bone_29", lshoulder, Ogre::Quaternion(1,0,0,0));
  this->_aura = new Particle("VERT", "Examples/AureolaVERT", mSceneMgr, mNode);
}

void Warrior::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}

void Warrior::attack(CollisionTools* collision, Ogre::SceneManager* mSceneMgr, RenderManager* render, const Ogre::FrameEvent &fe)
{
  GameObject *tmp;
  Ogre::Entity *entity;
  Ogre::SceneNode *node;
  SCheckCollisionAnswer	collider;

  entity = mSceneMgr->createEntity("WarriorHit", "cube.mesh");
  node = mSceneMgr->getRootSceneNode()->createChildSceneNode("WarriorHitNode", this->mNode->getPosition(), this->mNode->getOrientation());
  node->attachObject(entity);
  node->setScale(2, 1, 2);
  node->translate(Ogre::Vector3(200, 0, 0), Ogre::Node::TS_LOCAL);
  collider = collision->check_ray_collision(node->getPosition(),
					    node->getPosition() + Ogre::Vector3(60.0f, 60.0f, 60.0f), 200.0f, 100.0f, 1,
					    entity, true);
  if (!this->_csound["Weapon"]->getStatus())
  {
    this->_csound["Weapon"]->playAudio();
    if (collider.collided)
    {
      if ((tmp = render->searchEntities(collider.entity->getName())))
      {
	if (!collider.entity->getName().compare(0, 6, "Zombie") ||
	    !collider.entity->getName().compare(0, 4, "Boss") ||
	    !collider.entity->getName().compare(0, 8, "Skeleton"))
	{
	  this->_csound["GouleInjured"]->setAudioVolume(35);
	  this->_csound["GouleInjured"]->playAudio();
	  static_cast<Npc *>(tmp)->takeDamage(this->_attack);
	  if (static_cast<Npc *>(tmp)->isAlive() == false)
	  {
	    static_cast<Npc *>(tmp)->unsetEntity(mSceneMgr);
	    render->eraseEntities(static_cast<Npc *>(tmp));
	    collision->remove_entity(collider.entity);
	  }
	}
      }
    }
  }
  mSceneMgr->destroySceneNode(node);
  mSceneMgr->destroyEntity(entity);
}
