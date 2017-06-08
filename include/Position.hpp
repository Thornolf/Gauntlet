/*
** Position.hpp for Position in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 10:57:10 2017 Adrien Warin
** Last update Wed May 31 17:09:34 2017 Thomas Fossaert
*/

#ifndef		_POSITION__HPP_
# define	_POSITION__HPP_
# include	<OgreVector3.h>
# include	<regex>

class Position
{
private:
  int             _x;
  int             _y;
  int             _z;
  Ogre::Vector3   *_vector;

public:
  Position (int = 0, int = 0, int = 0);
  virtual ~Position ();
  Position (const Position&);
  Position &operator=(const Position&);
  bool operator==(const Position &);

  int		getXPosition() const;
  int		getYPosition() const;
  int		getZPosition() const;
  Ogre::Vector3	getVector() const;
  void		setXPosition(int);
  void		setYPosition(int);
  void		setZPosition(int);
  void		setPosition(int, int, int);
  void		stringToPosition(const std::string &);
};

#endif		/* !_POSITION__HPP_! */
