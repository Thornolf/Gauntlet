/*
** Audio.hpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/include/music
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Mon May 22 10:47:19 2017 Pierre
** Last update Wed Jun 14 16:16:32 2017 Pierre
*/

#ifndef   AUDIO_HPP_
# define  AUDIO_HPP_

#include <iostream>
#include <SFML/Audio.hpp>

class IAudio
{
public:
  virtual ~IAudio() {};

  virtual void loadAudio(std::string const& filename) = 0;
  virtual void playAudio() = 0;
  virtual void playAudio(std::string const& filename) = 0;
  virtual void stopAudio() = 0;

  virtual void setAudioVolume(float volume) = 0;
  virtual float getAudioVolume() const = 0;
};

#endif
