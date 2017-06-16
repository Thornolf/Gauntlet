/*
** goldStack.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Fri Jun 16 14:35:39 2017 Pierre
*/

#ifndef _GOLDSTACK_HPP_
#define _GOLDSTACK_HPP_

# include "GameObject/Loot/Loot.hpp"
# include "Configuration.hpp"

class goldStack : public Loot
{
public:
  goldStack(int x, int y, int z, int id);
  goldStack(goldStack const &);
  goldStack& operator=(goldStack const &);
  ~goldStack();

  /* Classes */

  void		setOgreBase(Ogre::SceneManager*);
  void		unsetEntity(Ogre::SceneManager *mSceneMgr);

  void     increaseScore(Configuration *);
  virtual bool isTaken(Pc const &);
};

#endif
