/*
** foodStack.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Tue Jun 13 08:46:31 2017 Thomas Fossaert
*/

#ifndef _FOODSTACK_HPP_
# define _FOODSTACK_HPP_

#include "GameObject/Loot/Loot.hpp"

class foodStack : public Loot
{
public:
  foodStack(int x, int y, int z, int id);
  foodStack(foodStack const &);
  foodStack& operator=(foodStack const &);
  ~foodStack();

  /* Classes */

  void		setOgreBase(Ogre::SceneManager*);
  void		Animate(const Ogre::FrameEvent&);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);

  void increaseHealth();
  virtual bool isTaken(Pc const &);
};

#endif
