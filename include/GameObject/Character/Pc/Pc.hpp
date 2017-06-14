/*
** Pc.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Wed May 31 11:09:05 2017 Quentin Baudet
*/

#ifndef		_PC_HPP_
# define	_PC_HPP_
# include	<iostream>
# include	<string>
# include	"GameObject/Character/Character.hpp"
# include	"Input/eventType.hpp"

class Device;

class Pc : public Character
{
public:
  Pc(const std::string &, int, int, int);
  Pc(Pc const &);
  Pc& operator=(Pc const &);
  virtual ~Pc();

  void			setDevice(Device *);
  void			setName(const std::string &);
  Device		*getDevice(void) const;
  const std::string	&getName(void) const;

  void		moveUp(void);
  void		moveDown(void);
  void		moveLeft(void);
  void		moveRight(void);

private:
  std::string						_name;
public:
  std::map<eventType, std::function<void(void)> >	_event;
};

#endif
