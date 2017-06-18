/*
** Character.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
** Last update Sun Jun 18 17:14:48 2017 Thomas Fossaert
*/

#ifndef		_CHARACTER_HPP_
# define	_CHARACTER_HPP_

# include "GameObject/GameObject.hpp"
# include "Audio/SoundSystem.hpp"
# include "Animation.hpp"

class RenderManager;

class Character : public GameObject
{
  public:
    Character(int x, int y, int z);
    Character(Character const &);
    Character& operator=(Character const &);
    virtual ~Character();

    void			setScore(int);
    void			gainHealth(int);
    void			Animate(const Ogre::FrameEvent&);
    void			takeDamage(int dmg);
    bool			isAlive() const;
    virtual void		attack(CollisionTools *, Ogre::SceneManager*, RenderManager *, const Ogre::FrameEvent &) {};
    int getSpeed() const;

  protected:
    int				_health;
    int				_attack;
    int				_cooldown;
    int				_speed;
    int				_range;
    std::unordered_map<std::string, Sound *>		_csound;
    std::unordered_map<std::string, Sound *>		_injuredSound;

    void			launchAnimation(const Ogre::FrameEvent& fe, State state);
    void			getDistance() const;
    int				getRange(void) const;
};

#endif
