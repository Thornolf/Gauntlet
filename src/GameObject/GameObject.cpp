/*
** GameObject.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 09:53:00 2017 Quentin Baudet
*/

#include "GameObject.hpp"

GameObject::GameObject(int x, int y, int z)
{
  _position = new Position(x, y, z);
}

GameObject::GameObject(GameObject const & other)
{
  _position = other._position;
}

GameObject& GameObject::operator=(GameObject const & other)
{
  _position = other._position;
  return *this;
}

GameObject::~GameObject() {}

Position* GameObject::getPosition() const
{
  return (this->_position);
}
