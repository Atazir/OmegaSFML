#include "Engine.hpp"
#include <iostream>

using namespace std;
Omega::GameState _gameState;

int x = 0;

void Omega::Initialize(void)
{
	//_gameState = Playing;
	cout << "This works" << endl;
	cin.get();
}

void Omega::Start(void)
{
	if (_gameState != Uninitialized)
	{
		cout << "This works too" << endl;
		cin.get();
		//return;
	}

	RenderWindow _mainWindow(VideoMode(1024, 768, 32), "OmegaGame");
	_gameState = Omega::Playing;

	cout << "Got here" << endl;
	cin.get();

	//_mainWindow.close();
}

bool Omega::isExiting()
{
	return true;
}

void Omega::GameLoop()
{
	x += 1;
	cout << x << endl;
	if (x >= 100000000)
		isExiting();
}
