/*
** Light.cpp for cpp_indie_studio in /home/gratte_r/Rendu/Teck_2/CPP/indie/cpp_indie_studio/src/light
**
** Made by Robin Grattepanche
** Login   <gratte_r@epitech.net>
**
** Started on  Thu Jun 01 22:22:37 2017 Robin Grattepanche
** Last update Fri Jun 02 14:10:13 2017 Robin Grattepanche
*/

#include			"Light/light.hpp"

light::light(Ogre::SceneManager *scene, std::string name, Ogre::Light::LightTypes type, int x, int y, int z)
{
	this->_name = name;
	this->_scene = scene;
	this->_type = type;
	this->_position = new Position(x, y, z);
	this->_diffColour = Ogre::ColourValue(1.0, 1.0, 1.0);
	this->_specColour = Ogre::ColourValue(1.0, 1.0, 1.0);
	this->_direction = Ogre::Vector3(0, -1, 0);

	this->_light = this->_scene->createLight(name);
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

// light::light(const light &obj, std::string name)
// {
// 	this->_name = name;
// 	this->_type = obj._type;
// 	this->_position = obj._position;
// 	this->_diffColour = obj._diffColour;
// 	this->_specColour = obj._specColour;
// 	this->_direction = obj._direction;
//
// 	this->_light = mSceneMgr->createLight(name);
// 	this->_light->setType(obj._type);
// 	this->_light->setDiffuseColour(obj._diffColour);
// 	this->_light->setSpecularColour(obj._specColour);
// 	this->_light->setPosition(obj._position->getVector());
// 	this->_light->setDirection(obj._direction);
// }
//
// light &light::operator=(const light &obj, std::string name)
// {
// 	this->_name = name;
// 	this->_type = obj._type;
// 	this->_position = obj._position;
// 	this->_diffColour = obj._diffColour;
// 	this->_specColour = obj._specColour;
// 	this->_direction = obj._direction;
//
// 	this->_light = mSceneMgr->createLight(name);
// 	this->_light->setType(obj._type);
// 	this->_light->setDiffuseColour(obj._diffColour);
// 	this->_light->setSpecularColour(obj._specColour);
// 	this->_light->setPosition(obj._position->getVector());
// 	this->_light->setDirection(obj._direction);
// 	return (*this);
// }

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
