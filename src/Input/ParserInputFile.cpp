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

std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	ParserInputFile::getArrayBindingFromFile(const std::string &path, std::vector<Pc*> playerList)
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
  else
  {
    this->_binding.clear();
    return this->_binding;
  }
  return (this->_binding);
}

void		ParserInputFile::addLineSaveToBinding(const std::string &line, std::vector<Pc*> playerList)
{
  eventType	event;
  OIS::KeyCode	key;
  unsigned long	pos;
  unsigned int	playerId;
  unsigned int	posPlayerList;
  Pc		*player = nullptr;
  std::string	buffer;

  buffer = line;
  /* get KeyCode */
  if ((pos = buffer.find(" \t")) == std::string::npos)
    return;
  try
  {
    key = static_cast<OIS::KeyCode>(std::stoi(line.substr(0, pos)));
    if (key < OIS::KC_UNASSIGNED || key > OIS::KC_MEDIASELECT)
      throw IndieException("Invalid binding configuration");
  }
  catch (std::exception &e)
  {
    throw IndieException(e.what());
  }
  /* get Pc */
  if ((pos = buffer.find(" \t")) == std::string::npos)
    return;
  try
  {
    if ((pos = buffer.find(" \t")) == std::string::npos)
      return;
    playerId = std::stoi(buffer.substr(0, pos));
    buffer = std::stoi(buffer.substr(pos + 1));
    if (playerId > playerList.size())
      throw IndieException("ID Player not set in the configuration but provided in BindingMapFile");
    posPlayerList = 0;
    for (auto it = playerList.begin(); it != playerList.end(); ++it)
    {
      if (posPlayerList == playerId)
	player = (*it);
      posPlayerList++;
    }
  }
  catch (std::exception &e)
  {
    throw IndieException(e.what());
  }
  /* get eventType */
  try
  {
    event = static_cast<eventType>(std::stoi(buffer));
    buffer = std::stoi(buffer.substr(pos + 1));
  }
  catch (std::exception &e)
  {
    throw IndieException(e.what());
  }
  this->_binding.insert(std::make_pair(key, std::make_pair(player, event)));
}