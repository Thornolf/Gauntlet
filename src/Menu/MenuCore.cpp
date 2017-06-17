/*
** MenuCore.cpp for cpp_indie_studio in /home/baudet_q/rendu/CPP/cpp_indie_studio/src/MenuCore
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed May 31 10:48:18 2017 Quentin Baudet
// Last update Fri Jun 16 13:35:12 2017 Robin Grattepanche
*/

#include <Menu/MenuItem.hpp>
#include "Menu/MenuCore.hpp"

Menu::Menu()
{
  std::vector<std::string>	items;

  items.push_back("Jouer");
  items.push_back("Scores");
  items.push_back("Parametres");
  items.push_back("Quitter");
  this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Gauntlet");
  this->setBackGround("dist/media/assetMenu/WallpaperMenu.jpg");
  this->_vecSprite.push_back(setImage("dist/media/assetMenu/Xperformed.png"));
  this->_vecSprite.push_back(setImage("dist/media/assetMenu/pain.png"));
  this->setLogo("dist/media/assetMenu/logo.png");
  this->setMenuItem(items);
  this->_menuHubEvent["Jouer"] = std::bind(&Menu::startGame, this);
  this->_menuHubEvent["Quitter"] = std::bind(&Menu::quit, this);
}

Menu::~Menu()
{
  if (this->_background.getTexture())
    delete this->_background.getTexture();
}

void	Menu::startGame()
{
  GameCore	game;

  this->_window->close();
  try
  {
    game.go();
  }
  catch (std::exception &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

void	Menu::quit()
{
  this->_window->close();
}

void			Menu::itemClicked(sf::Vector2i mousePosition)
{
  for (auto it = this->_menuItems.begin(); it != this->_menuItems.end(); ++it)
  {
    if ((mousePosition.x > it->_shape->getPosition().x) &&
	(mousePosition.x < (it->_shape->getPosition().x + it->_shape->getSize().x)) &&
	(mousePosition.y > it->_shape->getPosition().y) &&
	(mousePosition.y < (it->_shape->getPosition().y + it->_shape->getSize().y)))
    {
      auto itFunc = this->_menuHubEvent.find(it->_title->getString().toAnsiString());
      if (itFunc != this->_menuHubEvent.end())
	itFunc->second();
    }
  }
}

void			Menu::setMenuItem(const std::vector<std::string> &listValues)
{
  std::vector<MenuItem>	listItems;
  sf::Vector2f		pos;

  pos.x = 1020;
  pos.y= 350;
  for (auto it = listValues.begin(); it != listValues.end(); ++it)
  {
    listItems.push_back(MenuItem(*it, pos, sf::Vector2f(500, 100)));
    pos.y += 130;
  }
  this->_menuItems = listItems;
}

void		Menu::setLogo(const std::string &path)
{
  this->_logo = this->setImage(path);
  this->_logo.setScale(sf::Vector2f(0.45, 0.45));
  this->_logoAlpha = sf::Uint8(0);
  this->_logoSwitchValue = true;
  this->_logo.setPosition(sf::Vector2f(100, 200));
  this->_logo.setColor(sf::Color(255, 255, 255, this->_logoAlpha));
}

void		Menu::animateLogo(void)
{
  this->_logoAlpha = (this->_logoSwitchValue) ? this->_logoAlpha + sf::Uint8(1) : this->_logoAlpha - sf::Uint8(1);
  this->_logoSwitchValue = (this->_logoAlpha == 255) ? false : (this->_logoAlpha == 100) ? true : _logoSwitchValue;
  this->_logo.setColor(sf::Color(255, 255, 255, this->_logoAlpha));
}

void	Menu::setBackGround(const std::string &path)
{
  this->_background = this->setImage(path);
  this->_backgroundAlpha = 0;
  this->_background.setColor(sf::Color(255, 255, 255, this->_backgroundAlpha));
}

bool	Menu::increaseBgAlpha(void)
{
  int	delta = 1;

  this->_backgroundAlpha = (this->_backgroundAlpha + sf::Uint8(delta) >= sf::Uint8(255)) ? sf::Uint8(255) : this->_backgroundAlpha + sf::Uint8(delta);
  this->_background.setColor(sf::Color(255, 255, 255, this->_backgroundAlpha));
  return ((this->_backgroundAlpha != 255));
}

sf::Sprite	Menu::setImage(const std::string &path)
{
  sf::Texture	*texture = new sf::Texture;
  sf::Sprite	sprite;

  if (!texture->loadFromFile(path))
    throw IndieException("Cannot load the \"" + path + "\" asset");
  sprite.setTexture(*texture);
  return (sprite);
}

void	Menu::displayItems(void)
{
  for (auto it = this->_menuItems.begin(); it != this->_menuItems.end(); ++it)
  {
    this->_window->draw(*it->_shape);
    this->_window->draw(*it->_title);
  }
}

void	Menu::menuLoop(void)
{
  int					nb_frame = 1;
  std::vector<sf::Sprite>::iterator	it = this->_vecSprite.begin();

  while (this->_window->isOpen())
  {
    sf::Event	event;
    this->_window->clear();
    while (this->_window->pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	this->_window->close();
      if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	this->itemClicked(sf::Mouse::getPosition(*this->_window));

    }
    if (it != this->_vecSprite.end())
    {
      this->showEditor(*it);
      if (nb_frame % 1300 == 0)
	++it;
    }
    else
    {
      this->_window->draw(this->_background);
      this->animateLogo();
      this->_window->draw(this->_logo);
      if (!this->increaseBgAlpha())
	displayItems();
    }
    this->_window->display();
    nb_frame++;
  }
}

void	Menu::showEditor(sf::Sprite &picture)
{
  float		posX;
  float		posY;

  posX = 960 - (picture.getTexture()->getSize().x / 2);
  posY = 540 - (picture.getTexture()->getSize().y / 2);

  picture.setPosition(posX, posY);
  this->_window->draw(picture);
}