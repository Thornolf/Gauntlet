/*
** DeviceManager.hpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 08:57:19 2017 Guillaume CAUCHOIS
** Last update Wed May 31 08:57:19 2017 Guillaume CAUCHOIS
*/

#ifndef		_DEVICE_MANAGER__HPP_
# define	_DEVICE_MANAGER__HPP_
#include	<Ogre.h>
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