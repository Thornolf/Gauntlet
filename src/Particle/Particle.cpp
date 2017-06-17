/*
** Particle.cpp for Particle in /home/warin_a/TEK2/rendu/CPP/INDIE/cpp_indie_studio/src/Particle
**
** Made by Adrien Warin
** Login   <warin_a@epitech.net>
**
** Started on  Wed Jun 14 10:21:32 2017 Adrien Warin
// Last update Fri Jun 16 11:17:43 2017 Adrien Warin
*/

#include "Particle.hpp"

Particle::Particle(std::string name, std::string path, Ogre::SceneManager *scene, Ogre::SceneNode *objet)
{
    this->_name = name;
    this->_path = path;
    this->_ps = setParticle(scene);
    setObjet(objet);
}

Particle::~Particle ()
{

}

Ogre::ParticleSystem    *Particle::setParticle(Ogre::SceneManager *scene)
{
    return(scene->createParticleSystem(this->_name, this->_path));
}

void                    Particle::setObjet(Ogre::SceneNode *objet)
{
    objet->attachObject(this->_ps);
}

void                    Particle::destroy()
{
  this->_ps->removeAllEmitters();
}

Ogre::ParticleSystem* 			Particle::getPs() const
{
  return (this->_ps);
}

void 			Particle::clearParticle()
{
  this->_ps->clear();
}
