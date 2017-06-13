/*
** Device.cpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 09:02:12 2017 Guillaume CAUCHOIS
** Last update Wed May 31 09:02:12 2017 Guillaume CAUCHOIS
*/

#include "Input/ParserInputFile.hpp"
#include "Input/Device.hpp"
#include "GameObject/Character/Pc/Pc.hpp"

Device::Device(const std::string &name, DeviceManager *manager, OIS::Type &typeDev, Pc *player) :
  _name(name)
{
  this->_parser = new ParserInputFile;
  this->_device = manager->createObject(typeDev);
  this->_player = player;
  this->_binding = this->_parser->getArrayBindingFromFile(this->_name + ".cnf");
}

Device::~Device()
{
  if (this->_device != nullptr)
    delete this->_device;
  this->_parser->saveBindingInFile(this->_binding, this->_name + ".cnf");
  delete this->_parser;
}

Device	&Device::operator=(const Device &obj)
{
  this->_device = obj._device;
  this->_player = obj._player;
  return (*this);
}

void	Device::capture(void) const
{
  this->_device->capture();
}

/**
 * Cette fonction prend un paramètre un KeyEvent contenant une clé qui a été préssé
 * Pour cela elle vient vérifié dans un tableau de binding quelle action il faut
 * executé en fonction de la touche pressée
 * @param ke
 */
void	Device::keyPressed(const OIS::KeyEvent& ke)
{
  for (auto it = this->_binding.begin(); it != this->_binding.end(); ++it)
  {
    if (it->second == ke.key)
    {
      if (this->_player->_event.find(it->first) == this->_player->_event.end())
	throw IndieException("Event not implemented");
      for (auto it_action = this->_player->_event.begin(); it_action != this->_player->_event.end(); ++it_action)
      {
	if (it_action->first == it->first)
	  (it_action->second)();
      }
    }
  }
}

void	Device::keyReleased(const OIS::KeyEvent& ke)
{

}

void		Device::dumpBinding(void) const
{
  for (auto it = this->_binding.begin(); it != this->_binding.end(); ++it)
    std::cout << "EVENT [" << it->first << "]  => KEY [" << it-> second << "]" << std::endl;
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
