/*
** IndieException.hpp for cpp_indie_studio in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/include
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Mon May 22 10:50:20 2017 Robin Grattepanche
** Last update Mon May 22 11:02:05 2017 Robin Grattepanche
*/
#ifndef 		_INDIE_EXCEPTION_HPP_
# define 		_INDIE_EXCEPTION_HPP_

#include		<exception>
#include		<string>

class IndieException : public std::exception
{
	private:
		const std::string	_errMessage;

public:
	IndieException (std::string) throw();
	virtual ~IndieException () throw() {};
	virtual const char *what() const throw();
};

#endif 			/* !_INDIE_EXCEPTION_HPP_ */
