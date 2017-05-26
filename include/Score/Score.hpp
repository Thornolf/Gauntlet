/*
** Score.hpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 08:42:38 2017 Guillaume CAUCHOIS
** Last update Mon May 22 08:42:38 2017 Guillaume CAUCHOIS
*/

#ifndef		_SCORE__HPP_
# define	_SCORE__HPP_

# include	<map>
# include	<string>
# include	<ostream>
# include	<fstream>
# include	<sstream>
# include	<iostream>
# include	"IndieException.hpp"
# define	SCORE_FILE_SAVE "./scores.gntl"

class Score
{
public:
  Score();
  virtual ~Score();
  Score		&operator=(const Score &);

  void		addEntry(std::string, int);
  void		loadFromSave(void);
  void		saveInFile(void);
  std::map<std::string, int>	getLeaderBoard(void) const;
private:
  void		addLineSaveToScores(std::string);
  std::map<std::string, int>	_leaderboard;
};

#endif		/* _SCORE__HPP_ */