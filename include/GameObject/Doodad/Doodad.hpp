/*
** Doodad.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Sat Jun 10 16:22:51 2017 Thomas Fossaert
*/

#ifndef _Doodad_HPP_
#define _Doodad_HPP_

#include <iostream>
#include "GameObject/GameObject.hpp"

class Doodad : public GameObject
{
private:
  int			_id;
  int			_Sx;
  int			_Sy;
  int			_Sz;
  Ogre::Quaternion	_orientation;
  std::string		_deco;
public:
  Doodad(int, int, int, int, int, int, int, const Ogre::Quaternion &, const std::string &);
  Doodad(Doodad const &);
  Doodad& operator=(Doodad const &);
  ~Doodad();

  /* Classes */

  void		setOgreBase(Ogre::SceneManager*);
  /*void	launchScript(Ogre::SceneManager*, Ogre::SceneNode *, const Ogre::FrameEvent&);
  void		Animate(const Ogre::FrameEvent&);
  void    unsetEntity(Ogre::SceneManager *mSceneMgr);*/
};

#endif
