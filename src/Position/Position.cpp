/*
** Position.cpp for Position
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 09:37:41 2017 Adrien Warin
** Last update Wed May 31 17:09:20 2017 Thomas Fossaert
*/

#include "Position.hpp"

Position::Position(int pos_x, int pos_y, int pos_z)
{
  this->_x = pos_x;
  this->_y = pos_y;
  this->_z = pos_z;
  this->_vector = new Ogre::Vector3(_x, _y, _z);
}

Position::~Position () {}

Position::Position(const Position& other)
{
  this->_x = other._x;
  this->_y = other._y;
  this->_z = other._z;
  this->_vector = other._vector;

}

Position&	Position::operator=(const Position &other)
{
  this->_x = other._x;
  this->_y = other._y;
  this->_z = other._z;
  this->_vector = other._vector;
  return (*this);
}

bool	Position::operator==(const Position &other)
{
  if (this->_vector == other._vector)
    return (true);
  return (false);
}

int	Position::getXPosition() const
{
  return (this->_x);
}

int	Position::getYPosition() const
{
  return (this->_y);
}

int	Position::getZPosition() const
{
  return (this->_z);
}

Ogre::Vector3	Position::getVector() const
{
  return (*_vector);
}

void	Position::setXPosition(int new_pos_x)
{
  this->_x = new_pos_x;
  this->_vector->x += new_pos_x/*Ogre::Vector3(new_pos_x, 0, 0)*/;
}

void	Position::setYPosition(int new_pos_y)
{
  this->_y = new_pos_y;
  this->_vector->y += new_pos_y/*Ogre::Vector3(0, new_pos_y, 0)*/;
}

void	Position::setZPosition(int new_pos_z)
{
  this->_z = new_pos_z;
  this->_vector->z += new_pos_z/*Ogre::Vector3(0, 0, new_pos_z)*/;
}

void	Position::setPosition(int new_x, int new_y, int new_z)
{
  this->_x = new_x;
  this->_y = new_y;
  this->_z = new_z;
  setXPosition(new_x);
  setYPosition(new_y);
  setZPosition(new_z);
}

void		Position::stringToPosition(const std::string &line)
{
  std::regex	regex("[0-9]*");
  std::smatch	match;
  std::string	buf;

  if (!std::regex_search(line.begin(), line.end(), match, regex) || match.size() != 3)
    return;
  buf = match[1];
  this->setXPosition(std::atoi(buf.c_str()));
  buf = match[2];
  this->setYPosition(std::atoi(buf.c_str()));
  buf = match[3];
  this->setZPosition(std::atoi(buf.c_str()));
}