#include "Engine.hpp"
#include "SplashScreen.hpp"
#include <iostream>

using namespace std;
Omega::GameState _gameState;
sf::RenderWindow Omega::_mainWindow;
//This render window declaration is for line 42 to have a reference to else it throws an error, however it also gives me a break in the code (not sure why)


void Omega::Initialize(void)
{
	_gameState = ShowingSplash;
	//RenderWindow 
	//RenderWindow _mainWindow;
	_mainWindow.create(sf::VideoMode(1920, 1080, 32), "OmegaGame");
	while (_gameState = ShowingSplash)
	{
		SplashScreen::Show(_mainWindow);
	}
	
}

void Omega::Start(void)
{
	if (_gameState = Uninitialized)
	{
		cout << "GameState is uninitialized; quiting." << endl;
		cin.get();
		return;
	}

	//Creates the window
	//RenderWindow _mainWindow(VideoMode(1024, 768, 32), "OmegaGame");
	//_mainWindow = VideoMode(1024, 768, 32), "OmegaGame";

	//_gameState = Omega::Playing;
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
	//while (_mainWindow.isOpen())
	//{
	//	// check all the window's events that were triggered since the last iteration of the loop
	//	sf::Event event;
	//	while (_mainWindow.pollEvent(event))
	//	{
	//		// "close requested" event: we close the window
	//		if (event.type == sf::Event::Closed)
	//			_mainWindow.close();
	//	}
	//}
	switch (_gameState)
	{
		case ShowingSplash:
		{
			cout << "Showing Splash" << endl;
		}
		case Uninitialized:
		{

		}
		case Paused:
		{

		}
		case ShowingMenu:
		{

		}
		case Playing:
		{
			cout << "Playing" << endl;
		}
		case Exiting:
		{

		}
	}
}
