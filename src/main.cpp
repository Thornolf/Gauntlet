/*
** main.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 02 06:36:03 2017 Guillaume CAUCHOIS
** Last update Fri Jun 02 06:36:03 2017 Guillaume CAUCHOIS
*/

#include "GameCore.hpp"

/*
int	main()
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
*/

#include "MapManager.hpp"

int		main(void)
{
  MapManager	*mManager;

  std::srand(std::time(0));
  try
  {
    mManager = new MapManager("dist/bin/map.cfg");
    mManager->computeAbstractTree();
    mManager->dumpASTContent();
  }
  catch (IndieException &e)
  {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return (0);
}