#pragma once
#include "BaseComponent.hpp"
#include "SFML/Graphics.hpp"

struct Vector3
{
public:
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	float x, y, z;
};

class TransformComponent : public BaseComponent
{
public:
	void Awake();
	void Start();
	void Update();
	void LateUpdate();
};

