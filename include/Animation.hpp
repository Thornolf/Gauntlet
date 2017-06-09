/*
** Animation.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue May 30 12:29:30 2017 Thomas Fossaert
** Last update Fri Jun 09 08:52:09 2017 Thomas Fossaert
*/

#ifndef _ANIMATION_HPP_
#define _ANIMATION_HPP_

#include <OgreSkeleton.h>
#include "BaseGauntlet.hpp"

class Animation
{
public:
  Animation();
  Animation(Animation const &);
  Animation& operator=(Animation const &);
  ~Animation();

  /* Classes */
  Ogre::AnimationState *initAnimation(Ogre::AnimationState *AnimationState, const std::string&, Ogre::Entity *entity);
  Ogre::AnimationState *simpleAnimation(Ogre::AnimationState *, const std::string&, const Ogre::FrameEvent&, Ogre::Entity *);
  Ogre::AnimationState *loopAnimation(Ogre::AnimationState *, const std::string&, const Ogre::FrameEvent&, Ogre::Entity *);
};

#endif
