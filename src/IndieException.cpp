/*
** ArcadeException.cpp for cpp_indie_studio
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Mon May 22 10:56:34 2017 Robin Grattepanche
** Last update Mon May 22 10:59:37 2017 Robin Grattepanche
*/

#include	"IndieException.hpp"

IndieException::IndieException(std::string errMsg) throw() : _errMessage(errMsg) {}

const char		*IndieException::what() const throw()
{
  return (this->_errMessage.c_str());
}
