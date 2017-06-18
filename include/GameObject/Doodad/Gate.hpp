/*
** Gate.hpp for Gauntlet in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/include/Gate.hpp
**
** Made by Robin GRATTEPANCHE
** Login   <robin.grattepanche@epitech.eu>
**
** Started on  Sun Jun 18 13:41:38 2017 Robin GRATTEPANCHE
** Last update Sun Jun 18 13:41:38 2017 Robin GRATTEPANCHE
*/

#ifndef GAUNTLET_GATE_HPP
#define GAUNTLET_GATE_HPP

# include	"GameObject/GameObject.hpp"
# include	"Configuration.hpp"

class gate : public GameObject
{
  public:
    gate(int, int, int, int);
    gate(gate const &);
    gate& operator=(gate const &);
    virtual ~gate();

    void	setOgreBase(Ogre::SceneManager*);
    void	unsetEntity(Ogre::SceneManager *);

    bool	go(Pc const &);
};

#endif //GAUNTLET_GATE_HPP
