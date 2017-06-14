/*
** foodStack.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed Jun 14 17:01:01 2017 Pierre
*/

#include "GameObject/Loot/foodStack.hpp"

foodStack::foodStack(int x, int y, int z, int id) : Loot(x, y, z, id)
{
  mPosition = new Position(x, y, z);
  mNodeName = "goldStackNode" + std::to_string(id);
}

foodStack::foodStack(foodStack const & other) : Loot(other)
{
  (void) other;
}

foodStack& foodStack::operator=(foodStack const & other)
{
  (void) other;
  return *this;
}

foodStack::~foodStack()
{

}

void foodStack::setOgreBase(Ogre::SceneManager* mSceneMgr)
{

  mEntity = mSceneMgr->createEntity("foodStack" + std::to_string(_id), "world_expansion04_doodads_pandaren_pa_food_bakedwildfowl_01.m2_.mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(80.0f, 80.0f, 80.0f);
  mNode->setOrientation(1,1,0,0);
}


void foodStack::Animate(const Ogre::FrameEvent& fe)
{
  
}

void foodStack::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
}

bool foodStack::isTaken(Pc const & other)
{
  if (this->mPosition == other.getPosition())
    return (true);
  return (false);
}
