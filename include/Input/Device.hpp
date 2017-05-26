/*
** Device.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 24 12:17:41 2017 Guillaume CAUCHOIS
** Last update Wed May 24 12:17:41 2017 Guillaume CAUCHOIS
*/

#ifndef		_DEVICE__HPP_
# define	_DEVICE__HPP_
# include	<map>
# include	<OIS.h>
# include	<Ogre.h>
# include	"Pc.hpp"
# include	"Input/DeviceManager.hpp"
# include	"IndieException.hpp"

typedef enum	eventType
{
  EVENT_TYPE_MIN = 0,
  MOVE_UP = 0,
  MOVE_DOWN,
  MOVE_LEFT,
  MOVE_RIGHT,
  EVENT_TYPE_MAX = MOVE_RIGHT
}		eventType;

class Device
{
public:
  /* Canonical functions */
  Device(const std::string &name, DeviceManager *manager, OIS::Type typeDev, Pc *vendor);
  virtual ~Device();
  Device	&operator=(const Device &);

  void		capture(void) const;
  void		keyPressed(const OIS::KeyEvent&);
  void		keyReleased(const OIS::KeyEvent&);
  void		editBinding(const eventType &, const OIS::KeyCode &);
  std::map<eventType, OIS::KeyCode>	getBinding(void) const;

private:
  OIS::Object				*_device;
  Pc					*_vendor;
  std::map<eventType, OIS::KeyCode>	_binding;
};

#endif		/* !_DEVICE__HPP_ */