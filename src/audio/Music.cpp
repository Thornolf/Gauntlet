/*
** Music.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src/audio
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 10:47:47 2017 Pierre
** Last update Wed Jun 14 16:19:17 2017 Pierre
*/

#include "audio/Music.hpp"

Music::Music()
{
  _music.setRelativeToListener(false);
  _music.setVolume(100);
}

Music::~Music()
{

}

void Music::loadAudio(std::string const& filename)
{
  try
  {
    if (!_music.openFromFile(filename))
      throw "Bad audio path\n";
  }
  catch (const char * Msg)
  {
    std::cerr << Msg;
    exit(84);
  }
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
