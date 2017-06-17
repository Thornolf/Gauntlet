/*
** Light.cpp for cpp_indie_studio in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/src/light
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Thu Jun 01 22:22:37 2017 Robin Grattepanche
** Last update Fri Jun 16 18:17:40 2017 Adrien Warin
*/

#include			"Light/light.hpp"

light::light(Ogre::SceneManager *scene, Ogre::SceneNode *node, std::string name, Ogre::Light::LightTypes type, int x, int y, int z)
{
	this->_name = name;
	this->_scene = scene;
	this->_type = type;
	this->_position = new Position(x, y, z);
	this->_diffColour = Ogre::ColourValue(1.0, 1.0, 1.0);
	this->_specColour = Ogre::ColourValue(1.0, 1.0, 1.0);
	this->_direction = Ogre::Vector3(0, -1, 0);

	this->_light = this->_scene->createLight(name);
	node->attachObject(this->_light);
	this->_light->setType(type);
	this->_light->setDiffuseColour(this->_diffColour);
	this->_light->setSpecularColour(this->_specColour);
	this->_light->setPosition(this->_position->getVector());
	this->_light->setDirection(this->_direction);
}

light::~light()
{
	delete this->_position;
}

void			light::setDiffuseColour(Ogre::ColourValue newColour)
{
	this->_diffColour = newColour;
	this->_light->setDiffuseColour(newColour);
}

void			light::setSpecularColour(Ogre::ColourValue newColour)
{
	this->_specColour = newColour;
	this->_light->setSpecularColour(newColour);
}

void			light::setPosition(int x, int y, int z)
{
	if (this->_type != Ogre::Light::LT_DIRECTIONAL) {
		Position *tmp = new Position(x, y, z);
		this->_position = tmp;
		this->_light->setPosition(this->_position->getVector());
		delete tmp;
	}
}

void			light::setDirection(Ogre::Vector3 direction)
{
	if (this->_type != Ogre::Light::LT_POINT) {
		this->_direction = direction;
		this->_light->setDirection(direction);
	}
}
