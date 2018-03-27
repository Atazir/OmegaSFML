#include "WindowManager.hpp"
#include <ostream>

using namespace sf;

void WindowManager::Show(RenderWindow& renderWindow)
{
	Image splashImage;

	if (splashImage.loadFromFile("../../Assets/SplashScreen.jpeg") != true)
	{
		printf("Didn't load the file");
		return;
	}
	

	Sprite splashSprite;
	Texture splashTexture;
	splashTexture.loadFromImage(splashImage, IntRect());
	splashSprite.setTexture(splashTexture);

	renderWindow.clear();
	renderWindow.draw(splashSprite);
	renderWindow.display();

}