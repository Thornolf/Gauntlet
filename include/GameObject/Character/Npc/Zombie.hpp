/*
** Zombie.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
// Last update Thu Jun  1 11:25:51 2017 Guillaume CAUCHOIS
*/

#ifndef		_ZOMBIE__HPP_
# define	_ZOMBIE__HPP_

# include "GameObject/Character/Npc/Npc.hpp"

class Zombie : public Npc
{
public:
  Zombie(int x, int y, int z, int id);
  Zombie(Zombie const &);
  Zombie& operator=(Zombie const &);
  ~Zombie();

  /* Member functions */
  void		setOgreBase(Ogre::SceneManager*);
  Ogre::Vector3	launchScript(Ogre::SceneManager*, Ogre::SceneNode *);
  void		Animate(const Ogre::FrameEvent&);
  void    unsetEntity(Ogre::SceneManager *mSceneMgr);

};

#endif		/* _ZOMBIE__HPP_ */
