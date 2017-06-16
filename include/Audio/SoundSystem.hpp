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

# include "IAudio.hpp"

class Sound : public IAudio
{
  public:
    Sound();
    Sound(const std::string &, const std::string &);
    virtual ~Sound();

    void loadAudio(const std::string & , const std::string &);
    void playAudio();
    void stopAudio();
    void setAudioVolume(float volume);
    float getAudioVolume() const;
    sf::SoundSource::Status getStatus() const;
    std::string getCurrentName() const;
    void setCurrentName(const std::string &);
    void setLoop(bool);
    void setFilePath(std::string);
    std::string getFilePath() const ;

  private:
    std::string		_currSoundName;
    std::string		_filePath;
    sf::SoundBuffer	_buffer;
    sf::Sound		_sound;
};

#endif
