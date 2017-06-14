/*
** Device.hpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 08:55:51 2017 Guillaume CAUCHOIS
** Last update Tue Jun 13 15:20:34 2017 Thomas Fossaert
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
# include	"Configuration.hpp"


class Pc;

class Device
{
public:
  /* Canonical functions */
  Device(const std::string &name, DeviceManager *manager, OIS::Type typeDev, Configuration *);
  virtual ~Device();
  Device	&operator=(const Device &);

  void							capture(void) const;
  void							keyPressed(const OIS::KeyEvent&);
  void							keyReleased(const OIS::KeyEvent&);
  void							editBinding(const eventType &, Pc*, const OIS::KeyCode &);
  void							dumpBinding(void) const;
  std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	getBinding(void) const;

private:
  ParserInputFile					*_parser;
  const std::string					_name;
  OIS::Object						*_device;
  std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	_binding;
  Configuration						*_config;
};

#endif		/* !_DEVICE__HPP_ */
