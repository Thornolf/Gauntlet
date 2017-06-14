/*
** Particle.hpp for Particle in /home/warin_a/TEK2/rendu/CPP/INDIE/cpp_indie_studio/include
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Mon Jun 12 15:59:00 2017 Adrien Warin
** Last update Wed Jun 14 11:33:38 2017 Adrien Warin
*/

#ifndef PARTICLE_HPP_
# define PARTICLE_HPP_

#include <OgreParticleSystem.h>

#include "GameCore.hpp"
#include "GameObject/Character/Pc/Pc.hpp"
#include "GameObject/GameObject.hpp"

class Particle
{
    private:
        Ogre::ParticleSystem*   _ps;
        std::string             _name;
        std::string             _path;

    public:
        Particle (std::string name, std::string path, Ogre::SceneManager *scene, Ogre::SceneNode *objet);
        virtual ~Particle ();

        Ogre::ParticleSystem    *setParticle(Ogre::SceneManager *scene);
        void                    setObjet(Ogre::SceneNode *objet);
};

#endif
