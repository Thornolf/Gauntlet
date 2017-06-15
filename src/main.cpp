/*
** main.cpp for IndieStudio
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Fri Jun 02 06:36:03 2017 Guillaume CAUCHOIS
** Last update Thu Jun 15 10:49:08 2017 Robin Grattepanche
*/

#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>
#include	<SFML/System/Clock.hpp>

#include "GameCore.hpp"

int	main()
{
	int		check = 0;

  // try
  //   {
			sf::Window window(sf::VideoMode(1920, 1080), "Gaunlet");
			while (window.isOpen())
    		{
        	sf::Event event;
        	while (window.pollEvent(event))
        		{
            	if (event.type == sf::Event::Closed)
                	window.close();
									check = 1;
        		}
    		}
				window.display();

		if (check == 1)
			{
				GameCore		app;
				app.go();
			}
		// }
  // catch (Ogre::Exception const& e)
  //   {
  //     std::cerr << e.what() << " from " << e.getSource() << std::endl;
  //     return (0);
  //   }
  return (0);
}
