/*
** Source.c for OgreApp in /home/guillobits/workspace/epitech/cpp_indie_studio/src/Score/Source.c
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 08:14:24 2017 Guillaume CAUCHOIS
** Last update Mon May 22 08:14:24 2017 Guillaume CAUCHOIS
*/

#include "./Score/Score.hpp"

Score::Score() {}

Score::~Score() {}

Score	&Score::operator=(const Score &obj)
{
  this->_leaderboard = obj._leaderboard;
  return (*this);
}

std::map<std::string, int>	Score::getLeaderBoard() const
{
  return (this->_leaderboard);
}

void	Score::addEntry(std::string player_name, int score)
{
  if (player_name.find("=") != std::string::npos)
    throw IndieException("Invalid player name send to Score::addEntry");
  this->_leaderboard.insert(std::pair<std::string, int>(player_name, score));
}

void		Score::saveInFile()
{
  std::filebuf	fb;
  std::ostream	*os;

  if (fb.open(SCORE_FILE_SAVE, std::ios::out) == nullptr)
    throw IndieException("Cannot save the scores. No modification has been made.");
  os = new std::ostream(&fb);
  for (auto it = this->_leaderboard.begin(); it != this->_leaderboard.end(); ++it)
    *os << it->first << "=" << it->second << std::endl;
  fb.close();
}

void		Score::addLineSaveToScores(std::string buf)
{
  std::string	player_name;
  int		score;
  unsigned long	pos;

  if ((pos = buf.find("=")) == std::string::npos)
    throw IndieException("Invalid line format");
  player_name = buf.substr(0, pos);
  try
  {
    score = std::stoi(buf.substr(pos + 1));
  }
  catch (std::exception)
  {
    throw IndieException("Invalid line format");
  }
  this->addEntry(player_name, score);
}

void				Score::loadFromSave()
{
  std::ifstream			*file;
  std::map<std::string, int>	scores;
  std::stringstream		ss;
  char				tmp[256];

  file = new std::ifstream(SCORE_FILE_SAVE);
  if (*file)
  {
    this->_leaderboard.clear();
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
    this->_leaderboard = scores;
    return;
  }
}