/*
** MenuCore.hpp for cpp_indie_studio in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/include/Menu
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Thu Jun 15 13:19:07 2017 Robin Grattepanche
// Last update Fri Jun 16 13:34:22 2017 Robin Grattepanche
*/

#ifndef		MENU_HPP
# define	MENU_HPP
# include <iostream>
# include <vector>
# include <functional>
# include <SFML/Graphics.hpp>
# include <SFML/System/Clock.hpp>
# include <SFML/Window.hpp>
# include "Menu/MenuItem.hpp"
# include "IndieException.hpp"
# include "GameCore.hpp"

class Menu {
private:
  sf::RenderWindow					*_window;
  sf::Sprite						_background;
  sf::Sprite						_logo;
  sf::Uint8						_logoAlpha;
  bool							_logoSwitchValue;
  sf::Uint8						_backgroundAlpha;
  std::vector<sf::Sprite>				_vecSprite;
  std::vector<MenuItem>					_menuItems;
  std::map<std::string, std::function<void(void)> >	_menuHubEvent;

public:
  Menu ();
  virtual ~Menu ();

  void		startGame(void);
  void		quit(void);

  void		setMenuItem(const std::vector<std::string> &);
  void		itemClicked(sf::Vector2i);
  void		setLogo(const std::string &);
  void		animateLogo(void);
  void		setBackGround(const std::string &);
  bool		increaseBgAlpha(void);
  sf::Sprite	setImage(const std::string &);
  void		menuLoop();
  void		displayItems(void);
  void		showEditor(sf::Sprite &);
};

#endif /* !MENU_HPP */
