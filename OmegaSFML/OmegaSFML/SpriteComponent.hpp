#pragma once
#include <iostream>
#include "BaseComponent.hpp"
//#include "SFML\Window.hpp"
//#include "GameObjectManager.hpp"

class SpriteComponent: public BaseComponent
{
public:

	SpriteComponent();
	~SpriteComponent();

	void AddSprite(sf::Sprite sprite);

	void Draw();

	sf::Sprite m_Sprite;
	static int nextSpriteID;

	//Player Information
	sf::Image playerImage;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	//Enemy Information
	sf::Image enemyImage;
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
};

