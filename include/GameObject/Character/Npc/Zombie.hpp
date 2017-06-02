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

# include <OgreCamera.h>
# include <OgreEntity.h>
# include <OgreLogManager.h>
# include <OgreRoot.h>
# include <OgreViewport.h>
# include <OgreSceneManager.h>
# include <OgreRenderWindow.h>
# include <OgreConfigFile.h>
# include <iostream>

# include "GameObject/Character/Script.hpp"
# include "Position.hpp"
# include "Animation.hpp"
# include "GameObject/Character/Npc/Npc.hpp"

class Zombie : public Npc
{
public:
  Zombie(int x, int y, int z);
  Zombie(Zombie const &);
  Zombie& operator=(Zombie const &);
  ~Zombie();

  /* Member functions */
  void		setOgreBase(Ogre::SceneManager*);
  Ogre::Vector3	launchScript(Ogre::SceneNode *);
  void		Animate(const Ogre::FrameEvent&);
private:
  Ogre::AnimationState	*mAnimationState;
  Ogre::Entity		*mEntity;
  Ogre::SceneNode	*mNode;
  Script		*mScript;
  Position		*mPosition;
  Animation		*mAnimation;
};

#endif		/* _ZOMBIE__HPP_ */
