/*
** Configuration.hpp for IndieStudio in /home/guillobits/workspace/epitech/cpp_indie_studio/include/Configuration.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 13:07:27 2017 Guillaume CAUCHOIS
** Last update Sat Jun 17 22:53:17 2017 Thomas Fossaert
*/

#ifndef		_CONFIGURATION__HPP_
# define	_CONFIGURATION__HPP_
# include	"GameObject/Character/Pc/Pc.hpp"

class Configuration
{
public:
  /* Canonical functions */
  Configuration();
  virtual ~Configuration();
  Configuration		&operator=(const Configuration &);

  /* Member functions */
  std::vector<Pc*>	&getPlayers(void);
  void			addPlayer(Pc*);
  void			addScorePoint(int nbPoint);
  void      addKey();
  Pc*       getClosestPlayer(GameObject *);
  void      erasePlayer(Pc *);

  template <typename UnaryFunction>
  void			forEachPlayer(UnaryFunction f)
  {
    if (!this->_players.empty())
      std::for_each(this->_players.begin(), this->_players.end(), f);
  }

private:
  std::vector<Pc*>	_players;
  int			_score;
  bool    _key;
};

#endif		/* _CONFIGURATION__HPP_ */
