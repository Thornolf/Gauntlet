/*
** GameObject.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Mon May 22 11:18:53 2017 Thomas Fossaert
*/

#include "GameObject.hpp"

GameObject::GameObject()
{
}

GameObject::GameObject(GameObject const & other)
{
  (void) other;
}

GameObject& GameObject::operator=(GameObject const & other)
{
  (void) other;
  return *this;
}

GameObject::~GameObject()
{

}
