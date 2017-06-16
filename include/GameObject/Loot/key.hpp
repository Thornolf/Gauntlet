/*
** key.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri Jun 16 11:39:41 2017 Thomas Fossaert
*/

#ifndef _KEY_HPP_
# define _KEY_HPP_

#include "GameObject/Loot/Loot.hpp"

class key : public Loot
{
public:
  key(int x, int y, int z, int id);
  key(key const &);
  key& operator=(key const &);
  ~key();

  /* Classes */

  void		setOgreBase(Ogre::SceneManager*);
  void		Animate(const Ogre::FrameEvent&);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);

  virtual bool isTaken(Pc const &);
};

#endif
