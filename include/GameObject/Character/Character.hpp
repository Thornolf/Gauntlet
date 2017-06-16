/*
** Character.hpp for cpp_indie_studio in /home/fossae_t/rendu2/cpp_indie_studio/include
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Fri May 19 15:31:07 2017 Thomas Fossaert
<<<<<<< HEAD
** Last update Thu Jun 15 21:12:23 2017 Pierre
=======
** Last update Thu Jun 15 14:31:35 2017 Thomas Fossaert
>>>>>>> c83a29ce18df3011e6f6c2b8b7b129f47f82ed20
*/

#ifndef		_CHARACTER_HPP_
# define	_CHARACTER_HPP_

# include "GameObject/GameObject.hpp"
# include "Audio/SoundSystem.hpp"
# include "Animation.hpp"

class Character : public GameObject
{
  public:
    Character(int x, int y, int z);
    Character(Character const &);
    Character& operator=(Character const &);
    virtual ~Character();

    void 	gainHealth(int);
    void	Animate(const Ogre::FrameEvent&);

  protected:

    int							_health;
    int							_attack;
    int							_cooldown;
    int							_speed;
    int							_range;
    std::unordered_map<std::string, Sound *>		_csound;

    void		launchAnimation(const Ogre::FrameEvent& fe, State state);
    void		takeDamage(int dmg);
    void		attack(Character *target);
    bool		isAlive() const;
    void		getDistance() const;
    int			getRange(void) const;
};

#endif
