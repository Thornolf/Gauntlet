/*
** Animation.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Tue May 30 12:29:30 2017 Thomas Fossaert
** Last update Wed Jun 14 14:36:53 2017 Pierre
*/

#ifndef		_ANIMATION_HPP_
# define	_ANIMATION_HPP_

# include <Ogre.h>
# include <OgreSkeleton.h>

class Animation
{
private:
  std::string _name;
  bool _looping;
  double _dist;
  double _speed;
  double _castingTime;
  Ogre::AnimationState *_animationState;

public:
  Animation(std::string const&, bool, double speed = 1.0, double dist = 0.0, double castingTime = 0.5);
  Animation(Animation const &);
  Animation& operator=(Animation const &);
  ~Animation();

  bool		isLooping() const;
  bool		isCasted() const;
  void		addTime(float);
  void 		disable();
  void		setSpeed(double);
  void 		enable();
  const std::string 	&getName() const;
  void launch(const Ogre::FrameEvent& fe, Ogre::Entity*);
  bool		hasEnded() const;
  Ogre::AnimationState *getAnimationState() const;

  /* Classes */
  Ogre::AnimationState *initAnimation(Ogre::AnimationState *AnimationState, const std::string&, Ogre::Entity *entity);
  Ogre::AnimationState *simpleAnimation(Ogre::AnimationState *, const std::string&, const Ogre::FrameEvent&, Ogre::Entity *);
  Ogre::AnimationState *loopAnimation(Ogre::AnimationState *, const std::string&, const Ogre::FrameEvent&, Ogre::Entity *);
};

#endif		/* !_ANIMATION_HPP_! */
