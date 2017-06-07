/*
** RenderManager.cpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Jun 07 13:36:28 2017 Guillaume CAUCHOIS
** Last update Wed Jun 07 13:36:28 2017 Guillaume CAUCHOIS
*/

#include "RenderManager.hpp"

/*****************************************************************************/
RenderManager::RenderManager()
{
  this->_factory["DOODAD"] = std::bind(&RenderManager::createDoodadObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_factory["BOSS"] = std::bind(&RenderManager::createBossObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_factory["SKELETON"] = std::bind(&RenderManager::createSkeletonObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_factory["ZOMBIE"] = std::bind(&RenderManager::createZombieObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_factory["SPAWNER"] = std::bind(&RenderManager::createSpawnerObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_factory["FOOD"] = std::bind(&RenderManager::createFoodObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
  this->_factory["GOLD"] = std::bind(&RenderManager::createGoldObject, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
}

RenderManager::~RenderManager() {}

/*****************************************************************************/

/**
 * GameObject Factory Creation
 * @return GameObject*
 */
GameObject	*RenderManager::createGameObject(const std::string &type, const Position &pos, const Position &scale, const std::string &texture)
{
  static int	i = 1;

  return (this->_factory[type](i++, pos, scale, texture));
}


/******************************************************************************
 * Create Unit GameObject
 * @param id
 * @param position
 * @param scale
 * @param texture
 * @return GameObject
 */

GameObject	*RenderManager::createDoodadObject(int id, const Position &position, const Position &scale, const std::string &texture)
{
  return (nullptr);
}

GameObject	*RenderManager::createBossObject(int id, const Position &position, const Position &, const std::string &)
{
  return (new Boss(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createSkeletonObject(int id, const Position &position, const Position &, const std::string &)
{
  return (new Skeleton(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createZombieObject(int id, const Position &position, const Position &, const std::string &)
{
  return (new Zombie(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createSpawnerObject(int id, const Position &position, const Position &, const std::string &)
{
  return (new Spawner(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
  return (nullptr);
}

GameObject	*RenderManager::createFoodObject(int id, const Position &position, const Position &, const std::string &)
{
  return (new foodStack(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}

GameObject	*RenderManager::createGoldObject(int id, const Position &position, const Position &, const std::string &)
{
  return (new goldStack(position.getXPosition(), position.getYPosition(), position.getZPosition(), id));
}