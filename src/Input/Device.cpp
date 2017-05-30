/*
** Device.cpp for OgreApp in /home/guillobits/workspace/epitech/cpp_indie_studio/src/Input/Device.cpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 24 12:16:35 2017 Guillaume CAUCHOIS
** Last update Wed May 24 12:16:35 2017 Guillaume CAUCHOIS
*/

#include <Input/ParserInputFile.hpp>
#include "Input/Device.hpp"

Device::Device(const std::string &name, DeviceManager *manager, OIS::Type typeDev, Pc *vendor)
{
  ParserInputFile	parser;

  this->_device = manager->getIManager()->createInputObject(typeDev, false);
  this->_vendor = vendor;
  this->_binding = parser.getArrayBindingFromFile("./save/device/" + name + ".gnt_dev");
}

Device::~Device()
{
  if (this->_device != nullptr)
    delete this->_device;
}

Device	&Device::operator=(const Device &obj)
{
  this->_device = obj._device;
  this->_vendor = obj._vendor;
  return (*this);
}

void	Device::capture(void) const
{
  this->_device->capture();
}

void	Device::keyPressed(const OIS::KeyEvent& ke)
{
  switch (ke.key)
  {
    case OIS::KC_UP:
      break;
    case OIS::KC_DOWN:
      break;
    case OIS::KC_LEFT:
      break;
    case OIS::KC_RIGHT:
      break;
    default:
      break;
  }
}

void	Device::keyReleased(const OIS::KeyEvent& ke)
{
  switch (ke.key)
  {
    case OIS::KC_UP:
      break;
    case OIS::KC_DOWN:
      break;
    case OIS::KC_LEFT:
      break;
    case OIS::KC_RIGHT:
      break;
    default:
      break;
  }
}

void		Device::editBinding(const eventType &event, const OIS::KeyCode &key)
{
  std::map<eventType, OIS::KeyCode>::iterator	it;

  if ((it = this->_binding.find(event)) == this->_binding.end())
    throw IndieException("Event not exist");
  it->second = key;
}

std::map<eventType, OIS::KeyCode>	Device::getBinding(void) const
{
  return (this->_binding);
}