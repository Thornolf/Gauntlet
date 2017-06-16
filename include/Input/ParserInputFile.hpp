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

# include	<iostream>
# include	<map>
# include	<string>
# include	<sstream>
# include	<fstream>
# include	<OIS.h>
# include	"GameObject/Character/Pc/Pc.hpp"
# include	"Input/eventType.hpp"
# include	"IndieException.hpp"

class ParserInputFile
{
public:
  /* Constructor / Destructor */
  ParserInputFile();
  ~ParserInputFile();

  /* Public member functions */
  std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	getArrayBindingFromFile(const std::string &, const std::vector<Pc*> &playerList);
  void							saveBindingInFile(const std::map<OIS::KeyCode, std::pair<Pc *, eventType> > &data, const std::string &path, const std::vector<Pc *> playerList);
private:
  void							addLineSaveToBinding(const std::string &line, const std::vector<Pc*> &playerList);
  bool							stringIsNumber(char *line) const;

  std::map<OIS::KeyCode, std::pair<Pc *, eventType> >	_binding;
};

#endif		/* !_PARSER_INPUT_FILE__HPP_! */