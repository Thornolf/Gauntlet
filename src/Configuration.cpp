/*
** Configuration.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 13:58:14 2017 Guillaume CAUCHOIS
** Last update Mon May 22 13:58:14 2017 Guillaume CAUCHOIS
*/

#include "Configuration.hpp"

Configuration::Configuration() {}

Configuration::~Configuration() {}

Configuration	&Configuration::operator=(const Configuration &obj)
{
  this->_players = obj._players;
  return (*this);
}

std::vector<Pc>	Configuration::getPlayers(void) const
{
  return (this->_players);
}

void	Configuration::setPlayers(std::vector<Pc> players)
{
  this->_players = players;
}