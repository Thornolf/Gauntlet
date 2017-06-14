/*
** Pc.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 17:05:43 2017 Thomas Fossaert
** Last update Wed May 31 11:04:17 2017 Quentin Baudet
*/

#include "GameObject/Character/Pc/Pc.hpp"
#include "Input/Device.hpp"

Pc::Pc(const std::string &name, int x, int y, int z) : Character(x, y, z), _name(name)
{
  this->_event[eventType::MOVE_UP] = std::bind(&Pc::moveUp, this);
  this->_event[eventType::MOVE_DOWN] = std::bind(&Pc::moveDown, this);
  this->_event[eventType::MOVE_LEFT] = std::bind(&Pc::moveLeft, this);
  this->_event[eventType::MOVE_RIGHT] = std::bind(&Pc::moveRight, this);
}

Pc::Pc(Pc const & other) : Character(other)
{
}

Pc& Pc::operator=(Pc const & other)
{
  (void)other;
  return *this;
}

Pc::~Pc()
{
}

void	Pc::setName(const std::string &name)
{
  this->_name = name;
}

const std::string	&Pc::getName(void) const
{
  return (this->_name);
}

void		Pc::moveUp(void)
{
  std::cout << "Player is moving up" << std::endl;
}

void		Pc::moveDown(void)
{
  std::cout << "Player is moving down" << std::endl;
}

void		Pc::moveLeft(void)
{
  std::cout << "Player is moving left" << std::endl;
}

void		Pc::moveRight(void)
{
  std::cout << "Player is moving right" << std::endl;
}