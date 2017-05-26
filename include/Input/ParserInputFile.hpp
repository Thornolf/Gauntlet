/*
** ParserInputFile.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 24 16:49:41 2017 Guillaume CAUCHOIS
** Last update Wed May 24 16:49:41 2017 Guillaume CAUCHOIS
*/

#ifndef		_PARSER_INPUT_FILE__HPP_
# define	_PARSER_INPUT_FILE__HPP_
# include	"Input/Device.hpp"

class ParserInputFile
{
public:
  /* Constructor / Destructor */
  ParserInputFile();
  ~ParserInputFile();

  /* Public member functions */
  std::map<eventType, OIS::KeyCode>	getArrayBindingFromFile(const std::string &);
  void		saveBindingInFile(const std::map<eventType, OIS::KeyCode> &data) const;
private:
  void	addLineSaveToScores(const std::string &line);

  std::map<eventType, OIS::KeyCode>	_binding;
};

#endif		/* !_PARSER_INPUT_FILE__HPP_! */