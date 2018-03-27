#include "Engine.hpp"
#include "SpriteComponent.hpp"

sf::RenderWindow _mainWindow;

int SpriteComponent::nextSpriteID = 0;

SpriteComponent::SpriteComponent()
{
	AddSprite(m_Sprite);
}

SpriteComponent::~SpriteComponent()
{
	///empty for now. No need to destory yet.
}

void SpriteComponent::AddSprite(sf::Sprite sprite)
{
	///Can expand to add more sprites and objects etc as engine grows.
	if (nextSpriteID == 0)
	{
		std::cout << "Print Sprite Here" << std::endl;
		///Load sprite here for player.
		if (playerImage.loadFromFile("../../Assets/Sprites/qbert.png") != true)
		{
			std::cout << "Did not load player image." << std::endl;
			return;
		}

		playerTexture.loadFromImage(playerImage, sf::IntRect());
		playerSprite.setTexture(playerTexture);

		nextSpriteID++;
	}
	else
	{
		///Load enemy sprites here.
	}
}

void SpriteComponent::Draw()
{
	//std::cout << "Draw is being called" << std::endl;

	//RenderWindow _mainWindow;
	
	Omega::_mainWindow.clear();
	Omega::_mainWindow.draw(m_Sprite);
	Omega::_mainWindow.display();
	//std::cout << "Draw is being called" << std::endl;
}
