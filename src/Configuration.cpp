/*
** Configuration.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 13:58:14 2017 Guillaume CAUCHOIS
** Last update Sun Jun 18 10:33:46 2017 Thomas Fossaert
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

std::vector<Pc*>	&Configuration::getPlayers(void)
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

int	Configuration::getScore() const
{
  return (this->_score);
}
void Configuration::addKey()
{
  this->_key = true;
}

Pc*       Configuration::getClosestPlayer(GameObject *current)
{
  Pc *tmp;
  int aggroX = 0;
  int aggroZ = 0;
  int oldAggroX = 100000;
  int oldAggroZ = 100000;

  tmp = *(this->_players.begin());
  for (auto &it : this->_players)
    {
      aggroX = std::abs(current->getSceneNode()->getPosition().x - it->getSceneNode()->getPosition().x);
      aggroZ = std::abs(current->getSceneNode()->getPosition().z - it->getSceneNode()->getPosition().z);
      if (aggroZ + aggroX < oldAggroX + oldAggroZ)
        {
          oldAggroX = aggroX;
          oldAggroZ = aggroZ;
          tmp = it;
        }
    }
  return (tmp);
}

void Configuration::erasePlayer(Pc *player)
{
  int i = 0;

  for (auto &it :this->_players)
    {
      if (it == player)
        this->_players.erase(this->_players.begin() + i);
      i++;
    }
}
