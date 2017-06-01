/*
** Animation.cpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/src/Animation
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue May 30 12:34:40 2017 Thomas Fossaert
** Last update Thu Jun 01 10:42:36 2017 Pierre
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
  AnimationState = entity->getAnimationState(anim);
  AnimationState->setLoop(true);
  AnimationState->setEnabled(true);
  //AnimationState->setTimePosition(0);
  AnimationState->addTime(fe.timeSinceLastFrame);
  return (AnimationState);
}

Ogre::AnimationState *Animation::loopAnimation(Ogre::AnimationState *AnimationState, const Ogre::FrameEvent& fe, Ogre::Entity *entity)
{
  if (AnimationState->getTimePosition() + fe.timeSinceLastFrame > AnimationState->getLength())
  {
    AnimationState = entity->getAnimationState("Idle1");
    AnimationState->setLoop(true);
    AnimationState->setEnabled(true);
  }
  return (AnimationState);
}
