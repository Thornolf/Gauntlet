/*
** main.cpp for cpp_indie_studio in /home/pierre/Tek2/cpp_indie_studio/src
**
** Made by Pierre
** Login   <pierre@epitech.net>
**
** Started on  Wed May 24 10:40:34 2017 Pierre
** Last update Wed May 31 11:40:52 2017 Pierre
*/

#include "audio/Music.hpp"
#include "audio/SoundSystem.hpp"
#include "GameCore.hpp"

int						main()
{
  try
    {
      GameCore		app;
      app.go();
    }
  catch (Ogre::Exception const& e)
    {
      std::cerr << e.what() << " from " << e.getSource() << std::endl;
      return (0);
    }
  return (0);
}
