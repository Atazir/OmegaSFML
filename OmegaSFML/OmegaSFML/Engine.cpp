#include "Engine.hpp"
#include "SplashScreen.hpp"
#include <iostream>

using namespace std;
Omega::GameState _gameState;
//RenderWindow _mainWindow(VideoMode(1024, 768, 32), "OmegaGame");


void Omega::Initialize(void)
{
	//SplashScreen::Show();
}

void Omega::Start(void)
{
	if (_gameState != Uninitialized)
	{
		cout << "GameState is uninitialized; quiting." << endl;
		cin.get();
		//return;
	}

	RenderWindow _mainWindow(VideoMode(1024, 768, 32), "OmegaGame");
	_gameState = Omega::Playing;
	//cin.get(); //stall to show window is open

	while (_gameState != Exiting)
	{
		GameLoop();
	}

	if (_gameState = Exiting)
	{
		//_mainWindow.close();

	}
}

void Omega::GameLoop()
{
	
}
