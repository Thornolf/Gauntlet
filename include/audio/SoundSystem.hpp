/*
** SoundSystem.hpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/include/audio
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 10:45:48 2017 Pierre
** Last update Wed May 24 11:29:36 2017 Pierre
*/

#ifndef   SOUND_SYSTEM_HPP_
# define  SOUND_SYSTEM_HPP_

#include <string>
#include <map>
#include "IAudio.hpp"

class SoundSystem : public IAudio
{
public:
  SoundSystem();
  ~SoundSystem();

  virtual void loadAudio(std::string const& filename);
  virtual void playAudio();
  virtual void playAudio(std::string const& filename);
  virtual void stopAudio();

  virtual void setAudioVolume(float volume);
  virtual float getAudioVolume() const;

private:
  static float	m_volume;

  sf::SoundBuffer _buffer;
  sf::Sound _sound;
};

#endif
