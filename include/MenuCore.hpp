/*
** MenuCore.hpp for cpp_indie_studio in /home/baudet_q/rendu/CPP/cpp_indie_studio/include
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed May 31 10:35:54 2017 Quentin Baudet
** Last update Wed May 31 10:48:44 2017 Quentin Baudet
*/

#ifndef _MENUCORE_HPP_
#define _MENUCORE_HPP_

/*
Si probleme de compilation, commenter
la classe qui n'est peut être pas encore fonctionnelle
*/

#include "RenderManager.hpp"
#include "Score.hpp"
#include "Audio.hpp"
#include "Configuration.hpp"

class MenuCore {
private:
  RenderManager   *_renderManager;
  Score           *_score;
  Audio           *_audio;
  Configuration   *_configuration;

public:
  MenuCore ();
  void startMenu(void) {}
  virtual ~MenuCore ();
};

#endif  /* !_MENUCORE_HPP_ */
