/*
** goldStack.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Mon Jun 12 14:25:33 2017 Thomas Fossaert
*/

#include "GameObject/Loot/goldStack.hpp"

goldStack::goldStack(int x, int y, int z, int id) : Loot(x, y, z, id)
{
  mPosition = new Position(x, y, z);
  mNodeName = "goldStackNode" + std::to_string(id);
}

goldStack::goldStack(goldStack const & other) : Loot(other)
{
  (void) other;
}

goldStack& goldStack::operator=(goldStack const & other)
{
  (void) other;
  return *this;
}

goldStack::~goldStack()
{

}

void goldStack::setOgreBase(Ogre::SceneManager* mSceneMgr)
{

  mEntity = mSceneMgr->createEntity("goldStack" + std::to_string(_id), "world_azeroth_stranglethorn_passivedoodads_trolldungeonsacks_tr.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(80.0f, 80.0f, 80.0f);
  mNode->setOrientation(1,1,0,0);
}


void goldStack::Animate(const Ogre::FrameEvent& fe)
{

}

void goldStack::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}

bool goldStack::isTaken(Pc const & other)
{
  if (this->mPosition == other.getPosition())
    return (true);
  return (false);
}
