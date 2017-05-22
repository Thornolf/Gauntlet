/*
** Position.hpp for Position in /home/warin_a/TEK2/rendu/CPP/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon May 22 10:57:10 2017 Adrien Warin
** Last update Mon May 22 14:27:39 2017 Thomas Fossaert
*/

#ifndef POSITION_HPP_
# define POSITION_HPP_

#include <OgreVector3.h>

class Position
{
    private:
        int             _x;
        int             _y;
        int             _z;
        Ogre::Vector3   _vector;

    public:
        Position (int, int, int);
        ~Position ();
        Position (const Position&);
        Position &operator=(const Position&);

        int               getXPosition() const;
        int               getYPosition() const;
        int               getZPosition() const;
        Ogre::Vector3     getVector() const;
        void              setXposition(int);
        void              setYPosition(int);
        void              setZPosition(int);
        void              setPosition(int, int, int);
};

#endif
