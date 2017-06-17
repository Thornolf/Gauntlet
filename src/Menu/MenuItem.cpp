/*
** MenuItem.c for Gauntlet
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Sat Jun 17 15:15:53 2017 Guillaume CAUCHOIS
** Last update Sat Jun 17 15:15:53 2017 Guillaume CAUCHOIS
*/

#include "Menu/MenuItem.hpp"

/*****************************************************************************/
MenuItem::MenuItem(const std::string title, const sf::Vector2f pos, const sf::Vector2f scale)
{
  this->_font = new sf::Font();
  this->_font->loadFromFile("dist/media/assetMenu/Augusta.ttf");
  this->_title = new sf::Text();
  this->_title->setString(title);
  this->_title->setFont(*this->_font);
  this->_title->setCharacterSize(72);
  this->_title->setPosition(pos + sf::Vector2f(20, 5));
  this->_shape = new sf::RectangleShape(scale);
  this->_shape->setFillColor(sf::Color(135,89, 26, 225));
  this->_shape->setPosition(pos);
}

MenuItem::MenuItem(const MenuItem &obj)
{
  this->_shape = obj._shape;
  this->_title = obj._title;
}

MenuItem	&MenuItem::operator=(const MenuItem &obj)
{
  this->_shape = obj._shape;
  this->_title = obj._title;
  return (*this);
}

MenuItem::~MenuItem()
{
}