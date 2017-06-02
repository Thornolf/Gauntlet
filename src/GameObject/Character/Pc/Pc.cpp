/*
** Pc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:04:17 2017 Quentin Baudet
*/

#include "Pc.hpp"

Pc::Pc(const std::string &name, int x, int y, int z) : Character(x, y, z), _name(name)
{
  this->_device = nullptr;
}

Pc::Pc(Pc const & other) : Character(other)
{
  if (this->_device != nullptr)
    delete this->_device;
}

Pc& Pc::operator=(Pc const & other)
{
  (void)other;
  return *this;
}

Pc::~Pc()
{
  if (this->_device != nullptr)
  {
    delete this->_device;
  }
}

void	Pc::setDevice(Device *dev)
{
  this->_device = dev;
}

Device	*Pc::getDevice(void) const
{
  return (this->_device);
}

const std::string	&Pc::getName(void) const
{
  return (this->_name);
}