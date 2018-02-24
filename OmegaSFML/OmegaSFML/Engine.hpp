#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "GameObjectManager.hpp"

using namespace sf;

class Omega
{
public:
	static void Start();
	static void Initialize();

private:
	static void GameLoop();

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
};
