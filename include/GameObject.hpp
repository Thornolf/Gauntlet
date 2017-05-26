/*
** GameObject.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri May 26 17:40:05 2017 Quentin Baudet
*/

#ifndef _GAMEOBJECT_HPP_
#define _GAMEOBJECT_HPP_

#include "Position.hpp"

class GameObject
{
protected:
  /**_Animation;
  *_Texture;
  *_Mesh;*/
  Position *_position;
public:
  GameObject(int, int, int);
  GameObject(GameObject const &);
  GameObject& operator=(GameObject const &);
  virtual ~GameObject();

  /* Classes */
  Position* getPosition() const;
  void      hide() const;
};

#endif
