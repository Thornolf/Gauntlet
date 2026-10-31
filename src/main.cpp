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

#ifdef _WIN32
# include	<windows.h>
#endif

// Folder containing the running executable
static std::filesystem::path	executableDir()
{
#ifdef _WIN32
  wchar_t		buffer[MAX_PATH];
  DWORD			len = GetModuleFileNameW(nullptr, buffer, MAX_PATH);
  if (len == 0 || len == MAX_PATH)
    return {};
  return std::filesystem::path(buffer).parent_path();
#else
  std::error_code	ec;
  return std::filesystem::read_symlink("/proc/self/exe", ec).parent_path();
#endif
}

int	main()
{
  // All the assets are loaded relative to the game folder: use the current
  // directory if it is the game folder, else the folder of the executable
  // (installed / zipped game), else the source tree it was built from.
  std::error_code	ec;
  if (!std::filesystem::exists("dist/media", ec))
  {
    std::filesystem::path	exeDir = executableDir();
    if (!exeDir.empty() && std::filesystem::exists(exeDir / "dist" / "media", ec))
      std::filesystem::current_path(exeDir, ec);
#ifdef GAUNTLET_ROOT_DIR
    else
      std::filesystem::current_path(GAUNTLET_ROOT_DIR, ec);
#endif
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
