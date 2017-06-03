/*
** MapManager.hpp for cpp_indie_studio
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed May 31 15:49:11 2017 Quentin Baudet
** Last update Wed May 31 16:24:21 2017 Quentin Baudet
*/

#ifndef		_MAP_MANAGER_HPP_
# define	_MAP_MANAGER_HPP_

# include	<iostream>

class MapManager
{
public:
  MapManager(std::string);
  void loadFromFile();
  void fillUpSceneFromMap();
  void parseFile(std::string);
  virtual ~MapManager ();
private:
  std::string _filePath;
};

#endif		/* !_MAP_MANAGER_HPP_ */
