/*
** Music.cpp for Gauntlet in /home/baudet_q/rendu/CPP/cpp_indie_studio/src/audio/Music.cpp
**
** Made by Quentin BAUDET
** Login   <quentin.baudet@epitech.eu>
**
** Started on  Thu Jun 15 20:47:46 2017 Quentin BAUDET
** Last update Thu Jun 15 20:47:46 2017 Quentin BAUDET
*/

#include "Audio/Music.hpp"

Music::Music()
{
  this->_music.setRelativeToListener(false);
  this->_music.setVolume(10.0);
}

Music::Music(const std::string & pathFile, const std::string & newCurrMusic)
{
  this->_music.setRelativeToListener(false);
  this->_music.setVolume(10.0);
  this->loadAudio(pathFile, newCurrMusic);
}


void Music::loadAudio(const std::string & filename, const std::string & newCurrName)
{
  try
  {
    if (!this->_music.openFromFile(filename))
    {
      throw IndieException("Bad audio path");
    }
    this->setMusicFilePath(filename);
    this->setCurrentName(newCurrName);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(84);
  }
}

void Music::playAudio()
{
  try
  {
    if (!this->_music.openFromFile(this->getMusicFilePath()))
    {
      throw IndieException("Bad audio path");
    }
    this->_music.play();
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    exit(84);
  }
}

void Music::stopAudio()
{
  this->_music.stop();
}

void Music::setAudioVolume(float newVolume)
{
  this->_music.setVolume(newVolume);
}

float Music::getAudioVolume() const
{
  return (this->_music.getVolume());
}

sf::SoundSource::Status Music::getStatus() const
{
  return (this->_music.getStatus());
}

std::string Music::getCurrentName() const
{
  return (this->_currMusic);
}

void Music::setCurrentName(const std::string & newCurrMusic)
{
  this->_currMusic = newCurrMusic;
}

void Music::setLoop(bool newLoop)
{
  this->_music.setLoop(newLoop);
}

void Music::setMusicFilePath(std::string newMusicFilePath) {
  this->_musicFilePath = newMusicFilePath;
}
std::string Music::getMusicFilePath() const {
  return (this->_musicFilePath);
}

Music::~Music() {}