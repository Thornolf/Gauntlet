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
