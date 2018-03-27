#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

///Not using own Vectors, using SFML Vectors.
//struct Vector3
//{
//public:
//	Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
//	Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
//
//	float x, y, z;
//};
//
//struct Vector2
//{
//public:
//	Vector2() : x(0.0f), y(0.0f) {}
//	Vector2(float _x, float _y) : x(_x), y(_y) {}
//
//	float x, y;
//};

class BaseComponent
{
public:
	BaseComponent();
	~BaseComponent();

	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
};

