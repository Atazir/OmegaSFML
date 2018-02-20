#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

using namespace sf;

class Omega
{
public:
	static void Start();
	static void Initialize();

	static RenderWindow _mainWindow;
	
	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

private:
	static void GameLoop();
	
};
