/*
** Script.cpp for script in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/src/Script
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 15:24:56 2017 Adrien Warin
** Last update Sat Jun 10 14:56:33 2017 Thomas Fossaert
*/

#include "GameObject/Character/Script.hpp"

Script::Script ()
{
}

Script::~Script ()
{
}

Ogre::Vector3 Script::ZombieScript(Ogre::SceneNode *current, Ogre::SceneNode *target)
{
  int aggroX = 0;
  int aggroZ = 0;
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  aggroX = std::abs(current->getPosition().x - target->getPosition().x);
  aggroZ = std::abs(current->getPosition().z - target->getPosition().z);
  if (aggroX < 75 || aggroZ < 75)
    {
      if (current->getPosition().x < target->getPosition().x)
        dirVec.x = 75;
      if (current->getPosition().x > target->getPosition().x)
        dirVec.x = -75;
      if (current->getPosition().z > target->getPosition().z)
        dirVec.y = -75;
      if (current->getPosition().z < target->getPosition().z)
        dirVec.y = 75;
    }
  return (dirVec);
}

Ogre::Vector3 Script::SkeletonScript(Ogre::SceneNode *current, Ogre::SceneNode *target)
{
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  if (current->getPosition().x < target->getPosition().x)
    dirVec.x = 75;
  if (current->getPosition().x > target->getPosition().x)
    dirVec.x = -75;
  if (current->getPosition().z > target->getPosition().z)
    dirVec.z = -75;
  if (current->getPosition().z < target->getPosition().z)
    dirVec.z = 75;

  return (dirVec);
}

Ogre::Vector3 Script::BossScript(Ogre::SceneNode *current, Ogre::SceneNode *target)
{
  Ogre::Vector3 dirVec = Ogre::Vector3::ZERO;

  if (current->getPosition().x < target->getPosition().x)
    dirVec.x = 75;
  if (current->getPosition().x > target->getPosition().x)
    dirVec.x = -75;
  if (current->getPosition().z > target->getPosition().z)
    dirVec.z = -75;
  if (current->getPosition().z < target->getPosition().z)
    dirVec.z = 75;

  return (dirVec);
}

void Script::test()
{
}
