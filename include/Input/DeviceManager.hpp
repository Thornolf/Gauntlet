/*
** DeviceManager.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 24 13:51:00 2017 Guillaume CAUCHOIS
** Last update Wed May 24 13:51:00 2017 Guillaume CAUCHOIS
*/

#ifndef		_DEVICE_MANAGER__HPP_
# define	_DEVICE_MANAGER__HPP_

#include	<OIS.h>

class DeviceManager
{
public:
  DeviceManager(Ogre::RenderWindow *win);
  virtual ~DeviceManager();

  OIS::InputManager	*getIManager(void) const;
private:
  OIS::InputManager	*_iManager;
};

#endif		/* !_DEVICE_MANAGER__HPP_! */