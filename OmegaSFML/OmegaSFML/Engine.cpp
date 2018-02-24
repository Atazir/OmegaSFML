#include "Engine.hpp"
#include "SplashScreen.hpp"
#include "CheckResources.hpp"
#include <iostream>

using namespace std;
Omega::GameState Omega::_gameState;
RenderWindow Omega::_mainWindow;
GameObjectManager Omega::_gameObjectManager;

void Omega::Initialize(void)
{
	//CheckResources::PrintResults();
	CheckResources::CheckRequirements();
	_gameState = ShowingSplash;
	_mainWindow.create(sf::VideoMode(1920, 1080, 32), "OmegaGame");
}

void Omega::Start(void)
{
	while (_gameState != Exiting)
	{
		GameLoop();
	}
}

void Omega::GameLoop()
{
	switch (_gameState)
	{
		case Uninitialized:
		{
			cout << "GameState is uninitialized; quiting." << endl;
			cin.get();
			break;
		}
		case ShowingSplash:
		{
			cout << "Showing Splash..." << endl;
			if(_mainWindow.isOpen())
			{
				SplashScreen::Show(_mainWindow);
			}
			break;
		}
		case Paused:
		{
			cout << "Paused..." << endl;
			break;
		}
		case ShowingMenu:
		{
			cout << "Showing Menu..." << endl;
			break;
		}
		case Playing:
		{
			cout << "Playing..." << endl;
			break;
		}
		case Exiting:
		{
			cout << "Exiting..." << endl;
			cin.get();
			return;
		}
	}

	while (_mainWindow.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (_mainWindow.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
			{
				_gameState = Exiting;
				_mainWindow.close();
			}
		}
	}
}
