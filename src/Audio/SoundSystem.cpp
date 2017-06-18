/*
** SoundSystem.cpp for Gauntlet in /home/baudet_q/rendu/CPP/cpp_indie_studio/src/Audio/SoundSystem.cpp
**
** Made by Quentin BAUDET
** Login   <quentin.baudet@epitech.eu>
**
** Started on  Wed Jun 14 11:27:03 2017 Quentin BAUDET
** Last update Sun Jun 18 12:57:03 2017 Quentin BAUDET
*/

#include <IndieException.hpp>
#include "Audio/SoundSystem.hpp"

Sound::Sound()
{
}

Sound::Sound(const std::string & pathFile, const std::string & newCurrSoundName)
{
  this->_sound.setRelativeToListener(true);
  this->_sound.setVolume(100.0);
  this->loadAudio(pathFile, newCurrSoundName);
  this->setCurrentName(newCurrSoundName);
  this->setFilePath(pathFile);
}

void Sound::loadAudio(const std::string & pathFile, const std::string &  newCurrName)
{

  try
  {
    if (this->_buffer.loadFromFile(pathFile) == false)
    {
      throw IndieException("Bad audio path");
    }
    this->_sound.setBuffer(this->_buffer);
    this->setCurrentName(newCurrName);
    this->setFilePath(pathFile);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(84);
  }
}

void Sound::playAudio()
{
  std::cout << "Current sound : |" << this->_currSoundName << "| " << std::endl;
  _sound.play();
}

void Sound::stopAudio()
{
  _sound.stop();
}

void Sound::setAudioVolume(float newVolume)
{
  this->_sound.setVolume(newVolume);
}

float Sound::getAudioVolume() const
{
  return (_sound.getVolume());
}

sf::SoundSource::Status Sound::getStatus() const
{
  return (_sound.getStatus());
}

std::string Sound::getCurrentName() const
{
  return (this->_currSoundName);
}

void Sound::setCurrentName(const std::string &newCurrentName)
{
  this->_currSoundName = newCurrentName;
}

void Sound::setLoop(bool newLoop)
{
  this->_sound.setLoop(newLoop);
}

void Sound::setFilePath(std::string newFilePath) {
  this->_filePath  = newFilePath;
}

std::string Sound::getFilePath() const {
  return (this->_filePath);
}
Sound::~Sound() {}