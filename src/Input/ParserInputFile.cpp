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

void		ParserInputFile::saveBindingInFile(const std::map<eventType, OIS::KeyCode> &data, const std::string &path) const
{

}

std::map<eventType, OIS::KeyCode>	ParserInputFile::getArrayBindingFromFile(const std::string &path)
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
      this->addLineSaveToScores(ss.str());
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

void	ParserInputFile::addLineSaveToScores(const std::string &line)
{
  eventType	idx;
  OIS::KeyCode	value;
  unsigned long	pos;

  if ((pos = line.find("=")) == std::string::npos)
    return;
  try
  {
    idx = static_cast<eventType>(std::stoi(line.substr(0, pos)));
    if (idx < EVENT_TYPE_MIN || idx > EVENT_TYPE_MAX)
      throw IndieException("Invalid binding configuration for idx = " + idx);
    value = static_cast<OIS::KeyCode>(std::stoi(line.substr(pos + 1)));
    if (value < OIS::KC_UNASSIGNED || value > OIS::KC_MEDIASELECT)
      throw IndieException("Invalid binding configuration for value = " + value);
  }
  catch (std::exception e)
  {
    throw IndieException(e.what());
  }
  this->_binding[idx] = value;
}