#include "SplashScreen.hpp"
#include <ostream>

void SplashScreen::Show(RenderWindow & renderWindow)
{
	sf::Image image;
	if (image.loadFromFile("Images/SplashScreen.jpeg") != true)
	{
		printf("Didn't load the file");
		return;
	}

	//Sprite sprite(image);

	//renderWindow.draw(sprite);
	//renderWindow.display();

}
