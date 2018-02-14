#include "Engine.hpp"
#include <iostream>

using namespace std;
Omega::GameState _gameState;

void Omega::Initialize(void)
{
	
}

void Omega::Start(void)
{
	if (_gameState != Uninitialized)
	{
		cout << "This works too" << endl;
	}

	RenderWindow _mainWindow(VideoMode(1024, 768, 32), "OmegaGame");
	_gameState = Omega::Playing;

	//_mainWindow.close();
}

bool Omega::isExiting()
{
	return true;
}

void Omega::GameLoop()
{
	
}
