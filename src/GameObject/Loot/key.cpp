/*
** key.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
// Last update Fri Jun 16 13:03:04 2017 Thomas Fossaert
*/

#include "GameObject/Loot/key.hpp"

key::key(int x, int y, int z, int id) : Loot(x, y, z, id)
{
  mPosition = new Position(x, y, z);
  mNodeName = "keyNode" + std::to_string(id);
}

key::key(key const & other) : Loot(other)
{
  (void) other;
}

key& key::operator=(key const & other)
{
  (void) other;
  return *this;
}

key::~key()
{
}

void key::setOgreBase(Ogre::SceneManager* mSceneMgr)
{
  mEntity = mSceneMgr->createEntity("key" + std::to_string(_id), "world_expansion05_doodads_human_doodads_6hu_barracks_keyring01..mesh");
  mNode = mSceneMgr->getRootSceneNode()->createChildSceneNode(mNodeName, mPosition->getVector());
  mNode->attachObject(mEntity);
  mNode->setScale(280.0f, 280.0f, 280.0f);
  mNode->setOrientation(1,-1,1,1);
}


void key::Animate(const Ogre::FrameEvent& fe)
{

}

void key::unsetEntity(Ogre::SceneManager *mSceneMgr)
{
  mSceneMgr->destroyEntity(mEntity);
  this->_aura = new Particle(std::to_string(_id), "Examples/Key" , mSceneMgr, mNode);
  //this->_aura->destroy();
}

bool key::isTaken(Pc const & other)
{
  if (this->mPosition == other.getPosition())
    return (true);
  return (false);
}
