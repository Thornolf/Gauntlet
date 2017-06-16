/*
** MenuCore.hpp for cpp_indie_studio in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/include/Menu
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Thu Jun 15 13:19:07 2017 Robin Grattepanche
// Last update Fri Jun 16 13:34:22 2017 Robin Grattepanche
*/

#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>
#include	<SFML/System/Clock.hpp>

#include	"IndieException.hpp"

#ifndef MENU_HPP
# define MENU_HPP

class Menu {
private:
	sf::RenderWindow		*_window;
	sf::Sprite			_background;
	std::vector<sf::Sprite>		_vecSprite;
	sf::Font			_font;


public:
	Menu ();
	virtual ~Menu ();
	void									setFont(const std::string &);
	void									setBackGround(const std::string &);
	sf::Sprite						setImage(const std::string &);
	void									menuLoop();
	void									showEditor(sf::Sprite);

};

#endif /* !MENU_HPP */
