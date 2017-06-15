/*
** Configuration.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 13:58:14 2017 Guillaume CAUCHOIS
** Last update Fri Jun 09 16:09:21 2017 Adrien Warin
*/

#include "Configuration.hpp"

Configuration::Configuration()
{
  this->_score = 0;
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
  std::cout << "DEBUG - SIZE BEFORE : " << this->_players.size() << std::endl;
  this->_players.push_back(player);
  std::cout << "DEBUG - SIZE AFTER : " << this->_players.size() << std::endl;
}

void	Configuration::addScorePoint(int nbPoint)
{
  this->_score += nbPoint;
}