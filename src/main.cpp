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
#include	<filesystem>
#include	"Menu/MenuCore.hpp"

int	main()
{
  // All the assets are loaded relative to the repository root
#ifdef GAUNTLET_ROOT_DIR
  std::error_code	ec;
  if (!std::filesystem::exists("dist/media", ec))
    std::filesystem::current_path(GAUNTLET_ROOT_DIR, ec);
#endif
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
