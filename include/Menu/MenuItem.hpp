/*
** MenuItem.hpp for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Sat Jun 17 15:20:33 2017 Guillaume CAUCHOIS
** Last update Sat Jun 17 15:20:33 2017 Guillaume CAUCHOIS
*/

#ifndef		_MENU_ITEM__HPP_
# define	_MENU_ITEM__HPP_
# include	<SFML/Graphics.hpp>
# include	<string>

class MenuItem
{
public:
  MenuItem(const std::string, const sf::Vector2f, const sf::Vector2f);
  virtual ~MenuItem();
  MenuItem(const MenuItem &);
  MenuItem	&operator=(const MenuItem &);

  sf::Font		*_font;
  sf::Text		*_title;
  sf::RectangleShape	*_shape;
};

#endif		/* !_MENU_ITEM__HPP_! */