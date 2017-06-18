/*
** Script.cpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src/Script
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:24:56 2017 Adrien Warin
// Last update Sun Jun 18 17:06:36 2017 Thomas Fossaert
*/

#include "GameObject/Character/Script.hpp"
#include "GameObject/Character/Character.hpp"

Script::Script ()
{
}

Script::~Script ()
{
}

Ogre::Vector3 Script::ZombieScript(GameObject *current, GameObject *target)
{
  int aggroX = 0;
  int aggroZ = 0;
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
  SCheckCollisionAnswer collider = _collision->check_ray_collision(current->getSceneNode()->getPosition(),
								   current->getSceneNode()->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 100.0f, 100.0f, 1,
								   _entity, false);

  aggroX = std::abs(current->getSceneNode()->getPosition().x - target->getSceneNode()->getPosition().x);
  aggroZ = std::abs(current->getSceneNode()->getPosition().z - target->getSceneNode()->getPosition().z);
  if (!collider.collided)
  {
    if (aggroX < 175 && aggroZ < 175)
      dirVec.x = 1;
    else if (aggroX < 775 && aggroZ < 775)
    {
      dirVec += moveX(current, target);
      dirVec += moveZ(current, target);
    }
  }
  else
  {
    if (aggroX < 175 && aggroZ < 175)
      dirVec.x = 1;
    else
    {
      dirVec.x = (current->getSceneNode()->getPosition().x < collider.position.x) ? 530 : dirVec.x;
      dirVec.x = (current->getSceneNode()->getPosition().x > collider.position.x) ? -530 : dirVec.x;
      dirVec.z = (current->getSceneNode()->getPosition().z > collider.position.z) ? 530 : dirVec.z;
      dirVec.z = (current->getSceneNode()->getPosition().z < collider.position.z) ? -530 : dirVec.z;
      dirVec.x +=2;
    }
  }
  return (dirVec);
}

Ogre::Vector3 Script::SkeletonScript(GameObject *current, GameObject *target)
{
  int aggroX = 0;
  int aggroZ = 0;
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
  SCheckCollisionAnswer collider = _collision->check_ray_collision(current->getSceneNode()->getPosition(), current->getSceneNode()->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 100.0f, 100.0f, 1,
								   _entity, false);

  aggroX = std::abs(current->getSceneNode()->getPosition().x - target->getSceneNode()->getPosition().x);
  aggroZ = std::abs(current->getSceneNode()->getPosition().z - target->getSceneNode()->getPosition().z);
  if (!collider.collided)
  {
    if (aggroX < 200 && aggroZ < 200)
      dirVec.x = 1;
    else if (aggroX < 775 && aggroZ < 775)
    {
      dirVec += moveX(current, target);
      dirVec += moveZ(current, target);
    }
  }
  else
  {
    if (aggroX < 200 && aggroZ < 200)
      dirVec.x = 1;
    else
    {
      dirVec.x = (current->getSceneNode()->getPosition().x < collider.position.x) ? 530 : dirVec.x;
      dirVec.x = (current->getSceneNode()->getPosition().x > collider.position.x) ? -530 : dirVec.x;
      dirVec.z = (current->getSceneNode()->getPosition().z > collider.position.z) ? 530 : dirVec.z;
      dirVec.z = (current->getSceneNode()->getPosition().z < collider.position.z) ? -530 : dirVec.z;
      dirVec.x +=2;
    }
  }
  return (dirVec);
}

Ogre::Vector3 Script::BossScript(GameObject *current, GameObject *target)
{
  int aggroX = 0;
  int aggroZ = 0;
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;
  SCheckCollisionAnswer collider = _collision->check_ray_collision(current->getSceneNode()->getPosition(),
								   current->getSceneNode()->getPosition() + Ogre::Vector3(100.0f, 100.0f, 100.0f), 100.0f, 100.0f, 1,
								   _entity, false);

  aggroX = std::abs(current->getSceneNode()->getPosition().x - target->getSceneNode()->getPosition().x);
  aggroZ = std::abs(current->getSceneNode()->getPosition().z - target->getSceneNode()->getPosition().z);
  if (!collider.collided)
  {
    if (aggroX < 175 && aggroZ < 175)
      dirVec.x = 1;
    else if (aggroX < 775 && aggroZ < 775)
    {
      dirVec += moveX(current, target);
      dirVec += moveZ(current, target);
    }
  }
  else
  {
    if (aggroX < 175 && aggroZ < 175)
      dirVec.x = 1;
    else if (aggroX < 775 && aggroZ < 775)
    {
      dirVec.x = (current->getSceneNode()->getPosition().x < collider.position.x) ? -530 : dirVec.x;
      dirVec.x = (current->getSceneNode()->getPosition().x > collider.position.x) ? 530 : dirVec.x;
      dirVec.z = (current->getSceneNode()->getPosition().z > collider.position.z) ? 530: dirVec.z;
      dirVec.z = (current->getSceneNode()->getPosition().z < collider.position.z) ? -530: dirVec.z;
      dirVec.x +=2;
    }
  }
  return (dirVec);
}

void Script::setCollision(CollisionTools *collision, Ogre::Entity *entity)
{
  this->_collision = collision;
  this->_entity = entity;
}

Ogre::Vector3 Script::moveX(GameObject *current, GameObject *target)
{
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  dirVec.x = (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x) ? static_cast<Character*>(current)->getSpeed() : dirVec.x;
  dirVec.x = (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x) ? -static_cast<Character*>(current)->getSpeed() : dirVec.x;

  return (dirVec);
}

Ogre::Vector3 Script::moveZ(GameObject *current, GameObject *target)
{
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  dirVec.z = (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z) ? static_cast<Character*>(current)->getSpeed() : dirVec.z;
  dirVec.z = (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z) ? -static_cast<Character*>(current)->getSpeed() : dirVec.z;

  return (dirVec);
}

void Script::changeOrientation(GameObject *current, Ogre::Vector3 dirVec)
{
  if (dirVec.x <= dirVec.z)
    {
      if (dirVec.x < 0)
        current->getSceneNode()->setOrientation(Ogre::Quaternion(0, 0, 1, 0));
      else
        current->getSceneNode()->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
    }
  else
    {
      if (dirVec.z < 0)
        current->getSceneNode()->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
      else
        current->getSceneNode()->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
    }
}
