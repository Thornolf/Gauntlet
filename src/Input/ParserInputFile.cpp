/*
** ParserInputFile.cpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 09:04:59 2017 Guillaume CAUCHOIS
** Last update Wed May 31 09:04:59 2017 Guillaume CAUCHOIS
*/

#include "Input/ParserInputFile.hpp"

ParserInputFile::ParserInputFile() {}

ParserInputFile::~ParserInputFile() {}

void		ParserInputFile::saveBindingInFile(const std::map<OIS::KeyCode, std::pair<Pc *, eventType> > &data, const std::string &path, const std::vector<Pc *> playerList)
{
  std::ofstream	save_file(path, std::ios::out | std::ios::trunc);
  int		idPlayer = 0;
  int		posPlayerList;

  this->_binding = data;
  if (save_file)
  {
    for (auto it = this->_binding.begin(); it != this->_binding.end(); ++it)
    {
      posPlayerList = 0;
      for (auto itPlayerList = playerList.begin(); itPlayerList != playerList.end(); ++itPlayerList)
      {
	if ((*itPlayerList) == it->second.first)
	  idPlayer = posPlayerList;
	posPlayerList++;
      }
      save_file << it->first << " " << idPlayer << " " << it->second.second << std::endl;
    }
    save_file.close();
  }
  else
    throw IndieException("Cannot save the binding configuration");
}

std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	ParserInputFile::getArrayBindingFromFile(const std::string &path, const std::vector<Pc*> &playerList)
{
  std::ifstream				*file;
  std::stringstream			ss;
  char					tmp[256];

  file = new std::ifstream(path);
  if (*file)
  {
    this->_binding.clear();
    while (file->getline(tmp, 256))
    {
      ss << tmp;
      this->addLineSaveToBinding(ss.str(), playerList);
      ss.str("");
      ss.clear();
    }
  }
  return (this->_binding);
}

bool		ParserInputFile::stringIsNumber(char *line) const
{
  int		i = -1;

  while (line[++i])
  {
    if (line[i] < '0' || line[i] > '9')
      return (false);
  }
  return (true);
}

void		ParserInputFile::addLineSaveToBinding(const std::string &line, const std::vector<Pc*> &playerList)
{
  OIS::KeyCode	key;
  eventType	event;
  int		eventInt;
  unsigned int	playerId;
  unsigned int	posPlayer;
  Pc		*player = nullptr;
  char		*part;
  char		*line_c = new char[line.length() + 1];
  int		keyInt;

  std::strcpy(line_c, line.c_str());
  if (!(part = std::strtok(line_c, " \t")) || !stringIsNumber(part))
    return;
  keyInt = std::atoi(part);
  if (keyInt < 0 || keyInt > OIS::KeyCode::KC_MEDIASELECT)
    return;
  key = static_cast<OIS::KeyCode>(keyInt);
  if (!(part = std::strtok(NULL, " \t")) || !stringIsNumber(part))
    return;
  playerId = static_cast<unsigned int>(std::atoi(part));
  posPlayer = 0;
  if (playerId > playerList.size())
    return;
  for (auto itPlayer = playerList.begin(); itPlayer != playerList.end(); ++itPlayer)
  {
    if (posPlayer == playerId)
      player = *itPlayer;
    posPlayer++;
  }
  if (!player)
    return;
  if (!(part = std::strtok(NULL, " \t")) || !stringIsNumber(part))
    return;
  if ((eventInt = std::atoi(part)) < eventType ::EVENT_TYPE_MIN || eventInt > eventType ::EVENT_TYPE_MAX)
    return;
  event = static_cast<eventType>(eventInt);
  delete[] line_c;
  this->_binding.insert(std::make_pair(key, std::make_pair(player, event)));
}