/*
** Device.cpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 09:02:12 2017 Guillaume CAUCHOIS
** Last update Tue Jun 13 15:20:32 2017 Thomas Fossaert
*/

#include "Input/ParserInputFile.hpp"
#include "Input/Device.hpp"
#include "GameObject/Character/Pc/Pc.hpp"

Device::Device(const std::string &name, DeviceManager *manager, OIS::Type typeDev, Configuration *config) :
  _name(name)
{
  this->_parser = new ParserInputFile;
  this->_config = config;
  try
  {
    this->_device = manager->createObject(typeDev);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  this->_binding = this->_parser->getArrayBindingFromFile(this->_name + ".cnf", this->_config->getPlayers());
}

Device::~Device()
{
  if (this->_device != nullptr)
    delete this->_device;
  this->_parser->saveBindingInFile(this->_binding, this->_name + ".cnf", this->_config->getPlayers());
  delete this->_parser;
}

Device	&Device::operator=(const Device &obj)
{
  this->_device = obj._device;
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
  for (auto itBinding = this->_binding.begin(); itBinding != this->_binding.end(); ++itBinding)
  {
    OIS::KeyCode	key = itBinding->first;
    Pc			*player = itBinding->second.first;
    eventType		event = itBinding->second.second;

    for (auto itEvent = player->_event.begin(); itEvent != player->_event.end(); ++itEvent)
    {
      if (itEvent->first == event)
      {
	itEvent->second();
	return;
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
  {
    std::cout << "KEYBINDING - The key" << it->first << " is assigned to player " << it->second.first->getName();
    std::cout << " and event " << it->second.second << std::endl;
  }
}

void		Device::editBinding(const eventType &event, Pc *player, const OIS::KeyCode &key)
{
  for (auto it = this->_binding.begin(); it != this->_binding.end(); ++it)
  {
    if (it->second.second == event && it->second.first == player)
      this->_binding.erase(it);
  }
  this->_binding.insert(std::make_pair(key, std::make_pair(player, event)));
}

std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	Device::getBinding(void) const
{
  return (this->_binding);
}
