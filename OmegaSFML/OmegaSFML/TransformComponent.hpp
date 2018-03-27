#pragma once
#include "BaseComponent.hpp"
#include <iostream>

class TransformComponent: public BaseComponent
{
public:
	///Components personal Position, Rotation, and Scale (with Rotation and Scale not being use right now).
	sf::Vector2f m_Position;
	//Vector3 m_Rotation;
	//Vector3 m_Scale;

	TransformComponent();
	//~TransformComponent();

	void AddTransform(sf::Transform transform);

	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	
	sf::Transform m_Transform;
	sf::Transform transformMatrix;

	///Testing bools
	bool lateUpdateHappening = false;
	bool updateHappening = false;
};

