/*
** Spawner.cpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 07 16:11:45 2017 Guillaume CAUCHOIS
** Last update Wed Jun 07 16:11:45 2017 Guillaume CAUCHOIS
*/

#include "GameObject/Character/Npc/Spawner.hpp"

Spawner::Spawner(int posX, int posY, int posZ, int id) : Npc(posX, posY, posZ, id) {}

Spawner::Spawner(const Spawner &obj) : Npc(obj) {}

Spawner& Spawner::operator=(const Spawner &obj)
{
  return (*this);
}

Spawner::~Spawner() {}

void		Spawner::makeSpawnZombie(RenderManager &rManager) const
{
  rManager.createGameObject("ZOMBIE", *this->getPosition(), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0),"");
}

void		Spawner::makeSpawnSkeleton(RenderManager &rManager) const
{
  rManager.createGameObject("SKELTON", *this->getPosition(), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), "");
}

void		Spawner::makeSpawnBoss(RenderManager &rManager) const
{
  rManager.createGameObject("BOSS", *this->getPosition(), Position(0, 0, 0), Ogre::Quaternion(0, 0, 0, 0), "");
}

void		Spawner::makeSpawnRandomEntity(RenderManager &rManager) const
{
  int		type = std::rand() % 3;

  if (type == 0)
    this->makeSpawnZombie(rManager);
  else if (type == 1)
    this->makeSpawnBoss(rManager);
  else
    this->makeSpawnSkeleton(rManager);
}