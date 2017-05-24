/*
** Configuration.hpp for IndieStudio in /home/guillobits/workspace/epitech/cpp_indie_studio/include/Configuration.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Mon May 22 13:07:27 2017 Guillaume CAUCHOIS
** Last update Mon May 22 13:07:27 2017 Guillaume CAUCHOIS
*/

#ifndef		_CONFIGURATION__HPP_
# define	_CONFIGURATION__HPP_
# include	"Pc.hpp"

class Configuration
{
public:
  /* Canonical functions */
  Configuration();
  virtual ~Configuration();
  Configuration		&operator=(const Configuration &);

  /* Member functions */
  std::vector<Pc>	getPlayers(void) const;
  void			setPlayers(std::vector<Pc>);

private:
  std::vector<Pc>	_players;

};

#endif		/* _CONFIGURATION__HPP_ */