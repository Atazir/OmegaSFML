#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
#include "GameObjectManager.hpp"


using namespace sf;

class Omega
{
public:
	static void Start();
	static void Initialize();

private:
	static void GameLoop(sf::Time time);

	enum GameState { Uninitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };

	static GameState _gameState;
	static RenderWindow _mainWindow;
	static GameObjectManager _gameObjectManager;
};
