/*
** light.hpp for cpp_indie_studio in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/include/Light
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Thu Jun 01 22:22:39 2017 Robin Grattepanche
** Last update Sat Jun 17 11:42:47 2017 Adrien Warin
*/

#ifndef 			_LIGHT_HPP
#define 			_LIGHT_HPP

#include			<iostream>
#include			<string>
#include 			<fstream>
#include			<OgreRoot.h>
#include			<OgreLight.h>
#include			<OgreColourValue.h>
#include			<OgreSceneManager.h>
#include			<SdkTrays.h>

#include			"Position.hpp"

class light
{
		private:
			Ogre::Light							*_light;

			Ogre::SceneManager			*_scene;
			std::string							_name;
			Ogre::Light::LightTypes	_type;
			Ogre::ColourValue				_diffColour;
			Ogre::ColourValue				_specColour;
			Position								*_position;
			Ogre::Vector3						_direction;

		public:
			light (Ogre::SceneManager *, Ogre::SceneNode *, std::string, Ogre::Light::LightTypes, int, int, int);
			virtual ~light ();

			void		setDiffuseColour(Ogre::ColourValue);
			void		setSpecularColour(Ogre::ColourValue);
			void		setPosition(int, int, int);
			void		setDirection(Ogre::Vector3);
};

#endif 				/* !_LIGHT_HPP */
