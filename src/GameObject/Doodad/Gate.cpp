/*
** Gate.cpp for Gauntlet in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/src/Gate.cpp
**
** Made by Robin GRATTEPANCHE
** Login   <robin.grattepanche@epitech.eu>
**
** Started on  Sun Jun 18 13:41:32 2017 Robin GRATTEPANCHE
** Last update Sun Jun 18 13:41:32 2017 Robin GRATTEPANCHE
*/

#include	"GameObject/Doodad/Gate.hpp"

gate::gate(int x, int y, int z, int id) : GameObject(x, y, z)
{
  (void)id;
  mPosition = new Position(x, y, z);
  mNodeName = "gate";
}

gate::gate(gate const &other) : GameObject(other)
{
  (void)other;
}

gate&	gate::operator=(gate const &other)
{
  (void)other;
  return (*this);
}

gate::~gate() {}

void	gate::setOgreBase(Ogre::SceneManager *mSceneMgr)
{
  mEntity = mSceneMgr->createEntity("Gate", "world_generic_activedoodads_worldtreeportals_worldtreeportal_ni.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(20.0f, 20.0f, 20.0f);
  mNode->setOrientation(1, 0, 0, 0);
}

void	gate::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}

bool	gate::go(Pc const &other)
{
  if (this->mPosition == other.getPosition())
    return (true);
  return (false);
}