/*
** Device.hpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 08:55:51 2017 Guillaume CAUCHOIS
** Last update Wed May 31 08:55:51 2017 Guillaume CAUCHOIS
*/

#ifndef		_DEVICE__HPP_
# define	_DEVICE__HPP_
# include	<map>
# include	<string>
# include	<OIS.h>
# include	<Ogre.h>
# include	<fstream>
# include	<iostream>
# include	"Input/DeviceManager.hpp"
# include	"IndieException.hpp"
# include	"Input/ParserInputFile.hpp"
# include	"Input/eventType.hpp"


class Pc;

class Device
{
public:
  /* Canonical functions */
  Device(const std::string &name, DeviceManager *manager, OIS::Type &typeDev, Pc *vendor);
  virtual ~Device();
  Device	&operator=(const Device &);

  void		capture(void) const;
  void		keyPressed(const OIS::KeyEvent&);
  void		keyReleased(const OIS::KeyEvent&);
  void					editBinding(const eventType &, const OIS::KeyCode &);
  void						dumpBinding(void) const;
  std::map<eventType, OIS::KeyCode>	getBinding(void) const;

private:
  ParserInputFile					*_parser;
  const std::string					_name;
  OIS::Object						*_device;
  Pc							*_player;
  std::map<eventType, OIS::KeyCode>			_binding;
};

#endif		/* !_DEVICE__HPP_ */