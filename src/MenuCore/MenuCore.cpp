/*
** MenuCore.cpp for cpp_indie_studio in /home/baudet_q/rendu/CPP/cpp_indie_studio/src/MenuCore
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed May 31 10:48:18 2017 Quentin Baudet
// Last update Fri Jun 16 13:35:12 2017 Robin Grattepanche
*/

#include	"Menu/MenuCore.hpp"

Menu::Menu()
{
   this->_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Gaunlet");
  setFont("dist/media/assetMenu/Augusta.ttf");
  setBackGround("dist/media/assetMenu/WallparperMenu.jpg");
  this->_vecSprite.push_back(setImage("dist/media/assetMenu/Xperformed.png"));
  this->_vecSprite.push_back(setImage("dist/media/assetMenu/pain.png"));
}

Menu::~Menu() {}

void		Menu::setFont(const std::string &path)
{
  if (!this->_font.loadFromFile(path))
    throw IndieException("Cannot load the \"" + path + "\" asset" );
}

void		Menu::setBackGround(const std::string &path)
{
  sf::Texture texture;

  if (!texture.loadFromFile(path))
    throw IndieException("Cannot load the \"" + path + "\" asset" );
  this->_background.setTexture(texture);
}

sf::Sprite		Menu::setImage(const std::string &path)
{
  sf::Texture	texture;
  sf::Sprite	sprite;

  if (!texture.loadFromFile(path))
    throw IndieException("Cannot load the \"" + path + "\" asset" );
  sprite.setTexture(texture);
  return (sprite);
}

void					Menu::menuLoop(void)
{
  while (this->_window->isOpen())
    {
      //      showEditor(this->_vecSprite[0]);
      //  showEditor(this->_vecSprite[1]);
      this->_window->display();
    }
}

void					Menu::showEditor(sf::Sprite picture)
{
  int					alpha = 0;

  picture.setColor(sf::Color(255, 255, 255, alpha));
  this->_window->clear();
  for (size_t i = 0; i < 1000000; i++) {
    this->_window->draw(picture);
  }
}
