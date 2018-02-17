#include "SplashScreen.hpp"
#include <ostream>

void SplashScreen::Show(RenderWindow & renderWindow)
{
	sf::Image image;
	if (image.loadFromFile("../../Lib/Images/SplashScreen.jpeg") != true)
	{
		printf("Didn't load the file");
		return;
	}

	Sprite sprite;
	//sprite.loadTextureFromImage(image);
	sf::Texture texture;
	texture.loadFromImage(image, IntRect());
	sprite.setTexture(texture);

	//sf::Texture sprite;
	//sprite.loadFromImage(image);

	renderWindow.draw(sprite);
	renderWindow.display();

}
