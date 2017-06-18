/*
** HUD.hpp for Gauntlet in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/include/HUD/HUD.hpp
**
** Made by Robin GRATTEPANCHE
** Login   <robin.grattepanche@epitech.eu>
**
** Started on  Sat Jun 17 13:32:47 2017 Robin GRATTEPANCHE
** Last update Sat Jun 17 13:32:47 2017 Robin GRATTEPANCHE
*/

#ifndef GAUNTLET_HUD_HPP
#define GAUNTLET_HUD_HPP

#include	<OgreOverlay.h>
#include	<OgreOverlayManager.h>
#include	<OgreOverlayElement.h>
#include	<OgreOverlayContainer.h>
#include	<OgreTextAreaOverlayElement.h>
#include	<OgreFontManager.h>

class	HUD
{
  private:
    Ogre::OverlayManager				*_overlayManager;
    Ogre::OverlayContainer				*_panel;
    Ogre::Overlay					*_overlay;
    std::vector<Ogre::TextAreaOverlayElement *>		_vecText;
    std::vector<int>					_vecHp;

    Ogre::TextAreaOverlayElement *			_hudScore;

    Ogre::TextAreaOverlayElement	*createOnePlayer(int x, int y, std::string what, Ogre::ColourValue);
    void				addLife(std::string, int, int, int, Ogre::ColourValue);

  public:
    HUD(std::string);
    ~HUD();
    void				setupPanel(int, int, int, int, std::string);
    void				initTextPlayer();
    void				createPlayers();
    void				getPlayerHp(int);
    void				initLife();
    void				initScore(int, int, Ogre::ColourValue);
    void				updateScore(int);
    void				updateLife(int, std::string);
    void				showHUD();
};

#endif //GAUNTLET_HUD_HPP
