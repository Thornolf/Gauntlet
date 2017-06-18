/*
** main.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 02 06:36:03 2017 Guillaume CAUCHOIS
// Last update Fri Jun 16 13:40:05 2017 Robin Grattepanche
*/
#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<SFML/System/Clock.hpp>
#include	"Menu/MenuCore.hpp"

int	main(int argc, char **argv, char **arge)
{
  if (!arge || arge[0] == 0)
  {
    std::cerr << "Error: no X server can be reached" << std::endl;
    return (84);
  }
  try
  {
    Menu	*menu = new Menu();
    menu->menuLoop();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
    return (0);
  }
  return (0);
}
