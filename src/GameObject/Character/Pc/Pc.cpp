

/*
** Pc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Sat Jun 17 11:13:11 2017 Thomas Fossaert
*/

#include "GameObject/Character/Pc/Pc.hpp"
#include "GameObject/Character/Npc/Npc.hpp"
#include "RenderManager.hpp"
#include "Input/Device.hpp"

Pc::Pc(const std::string &name, int x, int y, int z) : Character(x, y, z), _name(name)
{
  this->_event[eventType::MOVE_UP] = std::bind(&Pc::moveUp, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8);
  this->_event[eventType::MOVE_LEFT] = std::bind(&Pc::moveLeft, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8);
  this->_event[eventType::MOVE_DOWN] = std::bind(&Pc::moveDown, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8);
  this->_event[eventType::MOVE_RIGHT] = std::bind(&Pc::moveRight, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8);
  this->_event[eventType::MOVE_ATTACK] = std::bind(&Pc::moveAttack, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4, std::placeholders::_5, std::placeholders::_6, std::placeholders::_7, std::placeholders::_8);
}

Pc::Pc(Pc const & other) : Character(other)
{
}

Pc& Pc::operator=(Pc const & other)
{
  return *this;
}

Pc::~Pc()
{
}

void	Pc::setName(const std::string &name)
{
  this->_name = name;
}

const std::string	&Pc::getName(void) const
{
  return (this->_name);
}

void		Pc::moveUp(const Ogre::FrameEvent &fe, Ogre::Vector3 &dirVec, Ogre::Vector3 &camVec, CollisionTools * collision, Ogre::SceneManager *mSceneMgr, RenderManager* render, bool & actionKey, Pc *player)
{
  this->getSceneNode()->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
  dirVec.x += this->_speed;
  this->setAnimation(fe, GameObject::RUN);
  this->setAnimationState();
//  camVec.z -= 1;
}

void		Pc::moveDown(const Ogre::FrameEvent &fe, Ogre::Vector3 &dirVec, Ogre::Vector3 &camVec, CollisionTools * collision, Ogre::SceneManager *mSceneMgr, RenderManager* render, bool & actionKey, Pc *player)
{
  this->getSceneNode()->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
  dirVec.x += this->_speed;
  this->setAnimation(fe, GameObject::RUN);
  this->setAnimationState();
  //camVec.z -= 1;
}

void		Pc::moveLeft(const Ogre::FrameEvent &fe, Ogre::Vector3 &dirVec, Ogre::Vector3 &camVec, CollisionTools * collision, Ogre::SceneManager *mSceneMgr, RenderManager* render, bool & actionKey, Pc *player)
{
  this->getSceneNode()->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
  dirVec.x += this->_speed;
  this->setAnimation(fe, GameObject::RUN);
  this->setAnimationState();
  //.camVec.x += 1;
}

void		Pc::moveRight(const Ogre::FrameEvent &fe, Ogre::Vector3 &dirVec, Ogre::Vector3 &camVec, CollisionTools * collision, Ogre::SceneManager *mSceneMgr, RenderManager* render, bool & actionKey, Pc *player)
{
  this->getSceneNode()->setOrientation(Ogre::Quaternion(0, 0, 1, 0));
  dirVec.x += this->_speed;
  this->setAnimation(fe, GameObject::RUN);
  this->setAnimationState();
  // camVec.x += 1;
}

void  Pc::moveAttack(const Ogre::FrameEvent &fe, Ogre::Vector3 &dirVec, Ogre::Vector3 &camVec, CollisionTools * collision, Ogre::SceneManager *mSceneMgr, RenderManager* render, bool & actionKey, Pc *player)
{
  if (actionKey == false)
  {
    this->setAnimation(fe, GameObject::ATTACK);
    this->setAnimationState();
    if (this->isCasted() == false)
      player->attack(collision, mSceneMgr, render, fe);
  }
  actionKey = true;
}

int		Pc::getSpeed(void) const
{
  return (this->_speed);
}

int		Pc::getHp(void) const
{
  return (this->_health);
}