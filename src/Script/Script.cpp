/*
** Script.cpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src/Script
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:24:56 2017 Adrien Warin
** Last update Sat Jun 17 11:58:46 2017 Thomas Fossaert
*/

#include "GameObject/Character/Script.hpp"

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
      dirVec.x = (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x) ? 123 : dirVec.x;
      dirVec.x = (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x) ? -123 : dirVec.x;
      dirVec.z = (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z) ? 123 : dirVec.z;
      dirVec.z = (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z) ? -123 : dirVec.z;
    }
  }
  else
  {
    if (aggroX < 175 && aggroZ < 175)
      dirVec.x = 1;
    else if (aggroX < 775 && aggroZ < 775)
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
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  dirVec.x = (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x) ? 75 : dirVec.x;
  dirVec.x = (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x) ? -75 : dirVec.x;
  dirVec.z = (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z) ? -75 : dirVec.z;
  dirVec.z = (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z) ? 75 : dirVec.z;
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
      dirVec.x = (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x) ? 205: dirVec.x;
      dirVec.x = (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x) ? -205: dirVec.x;
      dirVec.z = (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z) ? -205: dirVec.z;
      dirVec.z = (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z) ? 205: dirVec.z;
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
