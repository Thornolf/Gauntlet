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
# include	"Character.hpp"
# include	"Input/Device.hpp"

class Pc : public Character
{
public:
  Pc(const std::string &, int, int, int);
  Pc(Pc const &);
  Pc& operator=(Pc const &);
  virtual ~Pc();

  /* Classes */

  virtual void		attack();
  virtual void		takeDamage(int);
  virtual bool		isAlive();
  virtual void		getDistance();
  virtual int		getRange();
  void			setDevice(Device *);
  Device		*getDevice(void) const;
  const std::string	&getName(void) const;

private:
  Device		*_device;
  const std::string	_name;
};

#endif
