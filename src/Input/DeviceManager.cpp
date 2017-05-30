/*
** DeviceManager.cpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 24 13:55:40 2017 Guillaume CAUCHOIS
** Last update Wed May 24 13:55:40 2017 Guillaume CAUCHOIS
*/

#include <Ogre.h>
#include "Input/DeviceManager.hpp"

DeviceManager::DeviceManager(Ogre::RenderWindow *win)
{
  OIS::ParamList	pl;
  size_t		windowHnd = 0;

  std::ostringstream windowHndStr;
  win->getCustomAttribute("WINDOW", &windowHnd);
  windowHndStr << windowHnd;
  pl.insert(std::make_pair(std::string("WINDOW"), windowHndStr.str()));
  this->_iManager = OIS::InputManager::createInputSystem(pl);
}

DeviceManager::~DeviceManager() {}

OIS::InputManager	*DeviceManager::getIManager(void) const
{
  return (this->_iManager);
}