#include "OmegaEngine.hpp"

void OmegaEngine::Start(void)
{
	if (_gameState != Uninitialized)
		return;
	_mainWindow.create(sf::VideoMode(1024, 768, 32), "OmegaGame");
	_gameState = OmegaEngine::Playing;

	while (!IsExiting())
	{
		GameLoop();
	}
	_mainWindow.close();
}

void OmegaEngine::Initialize()
{
}

bool OmegaEngine::IsExiting()
{
	return false;
}

void OmegaEngine::GameLoop()
{
}
