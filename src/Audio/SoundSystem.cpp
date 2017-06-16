/*
** SoundSystem.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src/audio
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 11:07:04 2017 Pierre
** Last update Wed May 24 11:29:39 2017 Pierre
*/

#include "Audio/SoundSystem.hpp"

SoundSystem::SoundSystem()
{
}

SoundSystem::SoundSystem(const std::string & pathFile, const std::string & newCurrSoundName)
{
  this->_sound.setRelativeToListener(false);
  this->_sound.setVolume(100.0);
  this->loadAudio(pathFile, newCurrSoundName);
}

void SoundSystem::loadAudio(const std::string & fileName, const std::string &  newCurrName)
{
  this->_buffer = sf::SoundBuffer();
  this->_buffer.loadFromFile(fileName);
  this->setCurrentName(newCurrName);
}

void SoundSystem::playAudio()
{
  _sound.setVolume(100.0);
  _sound.setBuffer(_buffer);
  _sound.play();
}

void SoundSystem::stopAudio()
{
  _sound.stop();
}

void SoundSystem::setAudioVolume(float newVolume)
{
  this->_sound.setVolume(newVolume);
}

float SoundSystem::getAudioVolume() const
{
  return (_sound.getVolume());
}

sf::SoundSource::Status SoundSystem::getStatus() const
{
  return (_sound.getStatus());
}

std::string SoundSystem::getCurrentName() const
{
  return (this->_currSoundName);
}

void SoundSystem::setCurrentName(const std::string &newCurrentName)
{
  this->_currSoundName = newCurrentName;
}

void SoundSystem::setLoop(bool newLoop)
{
  this->_sound.setLoop(newLoop);
}
SoundSystem::~SoundSystem() {}