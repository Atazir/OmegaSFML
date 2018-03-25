#pragma once
#include <SFML\Graphics.hpp>
//#include<SFML\Graphics\Transform.hpp>
#include "TransformComponent.hpp"
#include <iostream>

class BaseComponent
{
public:
	BaseComponent();
	~BaseComponent();

	void AddTransform(TransformComponent* transform);

	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}

	//sf::Transform Transform(); //Can be given up to 9 ints to give it a selected matrix, otherwise only creates a default Transform.
	//TransformComponent* myTransform;

	
};

