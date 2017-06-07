/*
** Music.hpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/include/audio
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 10:35:36 2017 Pierre
** Last update Wed May 24 11:01:16 2017 Pierre
*/

#ifndef   MUSIC_HPP_
# define  MUSIC_HPP_

#include "IAudio.hpp"

class Music : public IAudio
{
public:
  Music();
  ~Music();

  virtual void loadAudio(std::string const& filename);
  virtual void playAudio();
  virtual void playAudio(std::string const& filename);
  virtual void stopAudio();

  virtual void setAudioVolume(float volume);
  virtual float getAudioVolume() const;

private:
  sf::Music _music;
};

#endif
