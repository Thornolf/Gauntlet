/*
** Ranged.hpp for Ranged in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 10:15:37 2017 Adrien Warin
** Last update Wed May 31 11:12:20 2017 Quentin Baudet
*/

#ifndef RANGED_HPP_
# define  RANGED_HPP_

#include <iostream>
#include "Pc.hpp"

class Ranged : public Pc
{
    private:

    public:
        Ranged (int, int, int);
        Ranged (Ranged const &);
        Ranged& operator=(Ranged const &);
        virtual ~Ranged ();

        /* Méthodes */

        virtual void attack();
        virtual void takeDamage(int dmg);
        virtual bool isAlive();
        virtual void getDistance();
        virtual int getRange();
};

#endif
