/*
** ParserInputFile.hpp for OgreApp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed May 31 08:59:30 2017 Guillaume CAUCHOIS
** Last update Wed May 31 08:59:30 2017 Guillaume CAUCHOIS
*/

#ifndef		_PARSER_INPUT_FILE__HPP_
# define	_PARSER_INPUT_FILE__HPP_

# include	<map>
# include	<string>
# include	<sstream>
# include	<fstream>
# include	<OIS.h>
# include	"Input/eventType.hpp"
# include	"IndieException.hpp"

class ParserInputFile
{
public:
  /* Constructor / Destructor */
  ParserInputFile();
  ~ParserInputFile();

  /* Public member functions */
  std::map<eventType, OIS::KeyCode>	getArrayBindingFromFile(const std::string &);
  void					saveBindingInFile(const std::map<eventType, OIS::KeyCode> &data, const std::string &path) const;
private:
  void		addLineSaveToScores(const std::string &line);

  std::map<eventType, OIS::KeyCode>	_binding;
};

#endif		/* !_PARSER_INPUT_FILE__HPP_! */