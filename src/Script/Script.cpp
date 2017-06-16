/*
** Script.cpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src/Script
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:24:56 2017 Adrien Warin
// Last update Wed Jun 14 20:26:36 2017 Thomas Fossaert
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
           if (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x)
            dirVec.x = 123;
           else if (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x)
            dirVec.x = -123;
           if (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z)
            dirVec.z = -123;
           else if (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z)
            dirVec.z = 123;
        }
    }
  else
    {
      if (aggroX < 175 && aggroZ < 175)
       dirVec.x = 1;
     else if (aggroX < 775 && aggroZ < 775)
      {
         if (current->getSceneNode()->getPosition().x < collider.position.x)
          dirVec.x = -30;
         if (current->getSceneNode()->getPosition().x > collider.position.x)
          dirVec.x = 30;
         if (current->getSceneNode()->getPosition().z > collider.position.z)
          dirVec.z = 30;
         if (current->getSceneNode()->getPosition().z < collider.position.x)
          dirVec.z = -30;
      }
  }
  return (dirVec);
}

Ogre::Vector3 Script::SkeletonScript(GameObject *current, GameObject *target)
{
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  if (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x)
    dirVec.x = 75;
  if (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x)
    dirVec.x = -75;
  if (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z)
    dirVec.z = -75;
  if (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z)
    dirVec.z = 75;

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
	         if (current->getSceneNode()->getPosition().x < target->getSceneNode()->getPosition().x)
	          dirVec.x = 205;
	         if (current->getSceneNode()->getPosition().x > target->getSceneNode()->getPosition().x)
	          dirVec.x = -205;
	         if (current->getSceneNode()->getPosition().z > target->getSceneNode()->getPosition().z)
	          dirVec.z = -205;
	         if (current->getSceneNode()->getPosition().z < target->getSceneNode()->getPosition().z)
	          dirVec.z = 205;
	      }
    }
  else
    {
      if (aggroX < 175 && aggroZ < 175)
       dirVec.x = 1;
     else if (aggroX < 775 && aggroZ < 775)
      {
         if (current->getSceneNode()->getPosition().x < collider.position.x)
          dirVec.x = -30;
         if (current->getSceneNode()->getPosition().x > collider.position.x)
          dirVec.x = 30;
         if (current->getSceneNode()->getPosition().z > collider.position.z)
          dirVec.z = 30;
         if (current->getSceneNode()->getPosition().z < collider.position.z)
          dirVec.z = -30;
      }
  }
  return (dirVec);
  /*int aggroX = 0;
  int aggroZ = 0;
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  aggroX = std::abs(current->getPosition().x - target->getPosition().x);
  aggroZ = std::abs(current->getPosition().z - target->getPosition().z);
  if (aggroX < 175 && aggroZ < 175)
    dirVec.x = 1;
  else if (aggroX < 775 && aggroZ < 775)
    {
      if (current->getPosition().x <= target->getPosition().x)
        {
	  current->setOrientation(Ogre::Quaternion(1, 0, 0, 0));
          dirVec.x = 230;
        }
      else if (current->getPosition().x > target->getPosition().x)
        {
          current->setOrientation(Ogre::Quaternion(0, 0, 1, 0));
          dirVec.x = 230;
	}
      else if (current->getPosition().z >= target->getPosition().z)
        {
	  current->setOrientation(Ogre::Quaternion(-0.7, 0, -0.7, 0));
          dirVec.x = 230;
	}
      else if (current->getPosition().z < target->getPosition().z)
        {
	  current->setOrientation(Ogre::Quaternion(-0.7, 0, 0.7, 0));
          dirVec.x = 230;
	}
}*/
  return (dirVec);
}

void Script::setCollision(CollisionTools *collision, Ogre::Entity *entity)
{
  this->_collision = collision;
  this->_entity = entity;
}
