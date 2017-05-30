/*
** Animation.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src/Animation
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue May 30 12:34:40 2017 Thomas Fossaert
** Last update Tue May 30 13:24:14 2017 Thomas Fossaert
*/

#include "Animation.hpp"

Animation::Animation ()
{

}

Animation::Animation(Animation const & other)
{
    (void) other;
}

Animation& Animation::operator=(Animation const & other)
{
    (void) other;
    return(*this);
}

Animation::~Animation ()
{

}

Ogre::AnimationState *Animation::simpleAnimation(Ogre::AnimationState *AnimationState, const std::string& anim, const Ogre::FrameEvent& fe, Ogre::Entity *entity)
{
  AnimationState = entity->getAnimationState("Walk");
  AnimationState->setLoop(true);
  AnimationState->setEnabled(true);
  AnimationState->addTime(fe.timeSinceLastFrame);
  return (AnimationState);
}
