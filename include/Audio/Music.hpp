/*
** Music.hpp for Gauntlet in /home/baudet_q/rendu/CPP/cpp_indie_studio/include/audio/Music.hpp
**
** Made by Quentin BAUDET
** Login   <quentin.baudet@epitech.eu>
**
** Started on  Thu Jun 15 20:47:37 2017 Quentin BAUDET
** Last update Thu Jun 15 20:47:37 2017 Quentin BAUDET
*/

#ifndef   MUSIC_HPP_
# define  MUSIC_HPP_

# include "IAudio.hpp"

class Music : public IAudio
{
  public:
    Music();
    Music(const std::string &, const std::string &);
    virtual ~Music();
    void loadAudio(const std::string & filename, const std::string &);
    void playAudio();
    void stopAudio();
    void setAudioVolume(float);
    float getAudioVolume() const;
    sf::SoundSource::Status getStatus() const;
    std::string getCurrentName() const;
    void setCurrentName(const std::string &);
    void setLoop(bool);
    void setMusicFilePath(std::string);
    std::string getMusicFilePath() const;

  private:
    sf::Music		_music;
    std::string		_currMusic;
    std::string		_musicFilePath;
};

#endif
