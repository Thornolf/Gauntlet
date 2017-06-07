/*
** SoundSystem.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src/audio
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 11:07:04 2017 Pierre
** Last update Wed May 24 11:29:39 2017 Pierre
*/

#include "audio/SoundSystem.hpp"

float	SoundSystem::m_volume = 100.0f;

SoundSystem::SoundSystem()
{

}

SoundSystem::~SoundSystem()
{

}

void SoundSystem::loadAudio(std::string const& filename)
{
  _buffer = sf::SoundBuffer();
  _buffer.loadFromFile(filename);
}

void SoundSystem::playAudio()
{
  _sound.setVolume(m_volume);
  _sound.setBuffer(_buffer);
  _sound.play();
}

void SoundSystem::playAudio(std::string const& filename)
{
  loadAudio(filename);
  _sound.setBuffer(_buffer);
  _sound.play();
}

void SoundSystem::stopAudio()
{

}

void SoundSystem::setAudioVolume(float volume)
{
  m_volume = volume;
}

float SoundSystem::getAudioVolume() const
{

}
