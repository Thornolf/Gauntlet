/*
** Configuration.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 13:58:14 2017 Guillaume CAUCHOIS
** Last update Sat Jun 17 16:32:22 2017 Thomas Fossaert
*/

#include "Configuration.hpp"

Configuration::Configuration()
{
  this->_score = 0;
  this->_key = false;
}

Configuration::~Configuration() {}

Configuration	&Configuration::operator=(const Configuration &obj)
{
  this->_score = obj._score;
  this->_players = obj._players;
  return (*this);
}

const std::vector<Pc*>	&Configuration::getPlayers(void) const
{
  return (this->_players);
}

void	Configuration::addPlayer(Pc* player)
{
  this->_players.push_back(player);
}

void	Configuration::addScorePoint(int nbPoint)
{
  this->_score += nbPoint;
}

void Configuration::addKey()
{
  this->_key = true;
}
