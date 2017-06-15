/*
** GameObject.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Thu Jun 15 10:11:35 2017 Thomas Fossaert
*/

#include "GameObject/GameObject.hpp"

GameObject::GameObject(int x, int y, int z)
{
  mPosition = new Position(x, y, z);
}

GameObject::GameObject(GameObject const & other)
{
  mPosition = other.mPosition;
}

GameObject& GameObject::operator=(GameObject const & other)
{
  mPosition = other.mPosition;
  return *this;
}

GameObject::~GameObject() {}

Position*	GameObject::getPosition() const
{
  return (this->mPosition);
}

void	GameObject::hide(void) {}

const std::string& GameObject::getNodeName() const
{
  return (mNodeName);
}

Ogre::Entity* GameObject::getEntity() const
{
  return (mEntity);
}

Ogre::SceneNode* GameObject::getSceneNode() const
{
  return (mNode);
}
