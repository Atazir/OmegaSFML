#include "WindowManager.hpp"
#include <ostream>

using namespace sf;

void WindowManager::Show(RenderWindow& renderWindow)
{
	Image image;

	if (image.loadFromFile("../../Assets/SplashScreen.jpeg") != true)
	{
		printf("Didn't load the file");
		return;
	}
	

	Sprite sprite;
	Texture texture;
	texture.loadFromImage(image, IntRect());
	sprite.setTexture(texture);

	renderWindow.clear();
	renderWindow.draw(sprite);
	renderWindow.display();

}