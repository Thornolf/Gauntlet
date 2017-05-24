/*
** Ranged.hpp for Ranged in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed May 24 10:15:37 2017 Adrien Warin
** Last update Wed May 24 11:06:15 2017 Adrien Warin
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

        virtual void getDamage();
        virtual void attack();
        virtual bool isAlive();
        virtual void getDistance();
        virtual size_t getRange();
};

#endif
