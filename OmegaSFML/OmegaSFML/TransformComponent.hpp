#pragma once
#include "BaseComponent.hpp"
#include <SFML/Graphics.hpp>
//#include <Transformable.hpp>

struct Vector3
{
public:
	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

	float x, y, z;
};

struct Vector2
{
public:
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}

	float x, y;
};

class TransformComponent : public BaseComponent
{
public:
	//Vector3f m_Position;
	//Vector3f m_Rotation;
	//Vector3f m_Scale;

	void Awake();
	void Start();
	void Update();
	void LateUpdate();

	//Transform m_Transform;
	//Transform transformMatrix;
};

