/*
** HUD.cpp for Gauntlet in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/src/HUD/HUD.cpp
**
** Made by Robin GRATTEPANCHE
** Login   <robin.grattepanche@epitech.eu>
**
** Started on  Sat Jun 17 13:33:11 2017 Robin GRATTEPANCHE
** Last update Sat Jun 17 13:33:11 2017 Robin GRATTEPANCHE
*/

#include	"HUD/HUD.hpp"

HUD::HUD(std::string panelName)
{
  this->_overlayManager = Ogre::OverlayManager::getSingletonPtr();
  this->_panel = static_cast<Ogre::OverlayContainer*>(this->_overlayManager->createOverlayElement("Panel", panelName));
  this->_panel->setMetricsMode(Ogre::GMM_PIXELS);
}

HUD::~HUD() {}

void	HUD::setupPanel(int x, int y, int sizeX, int sizeY, std::string path)
{
  this->_panel->setPosition(x, y);
  this->_panel->setDimensions(sizeX, sizeY);
  this->_panel->setMaterialName(path);
}

void	HUD::initTextPlayer()
{
  Ogre::TextAreaOverlayElement* textP1 = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", "Player1"));
  Ogre::TextAreaOverlayElement* textP2 = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", "Player2"));
  Ogre::TextAreaOverlayElement* textP3 = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", "Player3"));
  Ogre::TextAreaOverlayElement* textP4 = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", "Player4"));
  this->_vecText.push_back(textP4);
  this->_vecText.push_back(textP3);
  this->_vecText.push_back(textP2);
  this->_vecText.push_back(textP1);
}

void	HUD::createPlayers()
{
  this->_vecText[0] = this->createOnePlayer(20, 0, "Player1\n \tHP :", Ogre::ColourValue(0.6, 0.5, 0));
  this->_vecText[1] = this->createOnePlayer(270, 0, "Player2\n \tHP :", Ogre::ColourValue(0.9, 0.1, 0.1));
  this->_vecText[2] = this->createOnePlayer(650, 0, "Player3\n \tHP :", Ogre::ColourValue(0.2, 0.4, 0.9));
  this->_vecText[3] = this->createOnePlayer(935, 0, "Player4\n  HP  :", Ogre::ColourValue(0.1, 0.5, 0.1));

  this->_overlay = this->_overlayManager->create("Overlay");
  this->_overlay->add2D(this->_panel);

  this->_panel->addChild(this->_vecText[0]);
  this->_panel->addChild(this->_vecText[1]);
  this->_panel->addChild(this->_vecText[2]);
  this->_panel->addChild(this->_vecText[3]);

}

Ogre::TextAreaOverlayElement	*HUD::createOnePlayer(int x, int y, std::string what, Ogre::ColourValue color)
{
  Ogre::TextAreaOverlayElement* textArea = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", "p" + std::to_string(x)));
  textArea->setMetricsMode(Ogre::GMM_PIXELS);
  textArea->setPosition(x, y);
  textArea->setDimensions(20, 20);
  textArea->setParameter("font_name", "MyFont");
  textArea->setCaption(what);
  textArea->setCharHeight(50);
  textArea->setColour(color);
  return (textArea);
}

void				HUD::initScore(int x, int y, Ogre::ColourValue color)
{
  this->_hudScore = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", "hudScore"));
  this->_hudScore->setMetricsMode(Ogre::GMM_PIXELS);
  this->_hudScore->setPosition(x, y);
  this->_hudScore->setDimensions(20, 20);
  this->_hudScore->setParameter("font_name", "MyFont");
  this->_hudScore->setCaption(std::to_string(0));
  this->_hudScore->setCharHeight(70);
  this->_hudScore->setColour(color);
  this->_panel->addChild(this->_hudScore);
}

void				HUD::addLife(std::string name, int x, int y, int life, Ogre::ColourValue color)
{
  Ogre::TextAreaOverlayElement* textArea = static_cast<Ogre::TextAreaOverlayElement*>(_overlayManager->createOverlayElement("TextArea", name));
  textArea->setMetricsMode(Ogre::GMM_PIXELS);
  textArea->setPosition(x, y);
  textArea->setDimensions(20, 20);
  textArea->setParameter("font_name", "MyFont");
  textArea->setCaption(std::to_string(life));
  textArea->setCharHeight(70);
  textArea->setColour(color);
  this->_panel->addChild(textArea);
}

void				HUD::initLife()
{
  this->addLife("Tank", 170, 43, this->_vecHp[0], Ogre::ColourValue(0.6, 0.5, 0));
  this->addLife("Mage", 410, 43, this->_vecHp[1], Ogre::ColourValue(0.9, 0.1, 0.1));
  this->addLife("Archer", 800, 43, this->_vecHp[2], Ogre::ColourValue(0.2, 0.4, 0.9));
  this->addLife("Warrior", 1050, 43, this->_vecHp[3], Ogre::ColourValue(0.1, 0.5, 0.1));
}

void				HUD::updateLife(int hp, std::string name)
{
  this->_vecHp.clear();
  this->getPlayerHp(hp);
  this->_panel->getChild(name)->setCaption(std::to_string(this->_vecHp[0]));
}

void				HUD::updateScore(int score)
{
  this->_panel->getChild("hudScore")->setCaption(std::to_string(score));
}

void				HUD::getPlayerHp(int hp)
{
  this->_vecHp.push_back(hp);
}

void				HUD::showHUD()
{
  this->_overlay->show();
}