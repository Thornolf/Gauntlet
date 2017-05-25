/*
** Position.cpp for Position
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 09:37:41 2017 Adrien Warin
** Last update Thu May 25 16:26:12 2017 Thomas Fossaert
*/

#include "Position.hpp"

Position::Position(int pos_x, int pos_y, int pos_z)
{
  this->_x = pos_x;
  this->_y = pos_y;
  this->_z = pos_z;
  this->_vector = Ogre::Vector3(_x, _y, _z);
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
  return (_vector);
}

void	Position::setXposition(int new_pos_x)
{
  this->_x = new_pos_x;
  this->_vector += Ogre::Vector3(new_pos_x, 0, 0);
}

void	Position::setYPosition(int new_pos_y)
{
  this->_y = new_pos_y;
  this->_vector += Ogre::Vector3(0, new_pos_y, 0);
}

void	Position::setZPosition(int new_pos_z)
{
  this->_z = new_pos_z;
  this->_vector += Ogre::Vector3(0, 0, new_pos_z);
}

void	Position::setPosition(int new_x, int new_y, int new_z)
{
  this->_x = new_x;
  this->_y = new_y;
  this->_z = new_z;
  this->_vector = Ogre::Vector3(new_x, new_y, new_z);
}
