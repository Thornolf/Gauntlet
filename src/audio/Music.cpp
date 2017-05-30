/*
** Music.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src/audio
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 10:47:47 2017 Pierre
** Last update Wed May 24 14:02:08 2017 Pierre
*/

#include "audio/Music.hpp"

Music::Music()
{
  _music.setRelativeToListener(false);
}

Music::~Music()
{

}

void Music::loadAudio(std::string const& filename)
{
  if (!_music.openFromFile(filename))
    return ;
}

void Music::playAudio()
{
  this->_music.setLoop(true);
  this->_music.play();
}

void Music::playAudio(std::string const& filename)
{
  loadAudio(filename);
  _music.setLoop(true);
  _music.play();
}

void Music::stopAudio()
{
  _music.setLoop(false);
  _music.stop();
}

void Music::setAudioVolume(float volume)
{
  _music.setVolume(volume);
}

float Music::getAudioVolume() const
{
  _music.getVolume();
}
