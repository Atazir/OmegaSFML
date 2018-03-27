#include "BaseComponent.hpp"
#include <cmath>
#pragma once

using namespace sf;

struct AABB
{
	Vector2f bLeft;
	Vector2f tRight;
};

class RigidbodyComponent : public BaseComponent
{
public:

	float mass = 1.0f;
	float bounciness = 1.0f;

	bool obeysGravity = true;
	Vector2f gravity = Vector2f(0.0f, -9.8f);

	Vector2f currentVelocity;
	Vector2f maxVelocity = Vector2f(10.0f, 10.0f);

	bool grounded;

	AABB aabb;
	FloatRect boundingBox;
	

	//Rect(Vector2f(0.0f, 0.0f), Vector2f(1.0f, 1.0f))

	static Vector2f temp; ///REQUIRES DECLARATION IN THE CPP IN ORDER TO USE STATIC FILES
	
	void AddForce(Vector2f force);

	void Stop();
	

	void Awake();
	void Start();
	
	void SetAABB();
	void Integrate(float dT);

	bool isGrounded();

private:
	Vector2f totalForces;
};

