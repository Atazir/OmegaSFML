#pragma once
#include <cmath>
//#include <math.h>
#include <vector>
#include <map>
//#include "GameObjectManager.hpp"
#include "RigidbodyComponent.hpp"

struct CollisionPair
{
	///Rigisbody 1
	RigidbodyComponent* rigidbodyA;
	///Rigidbody 2
	RigidbodyComponent* rigidbodyB;
};

struct CollisionInfo
{
	Vector2f collisionNormal;
	float penetration;
};

class PhysicsManager
{
public:
	const float groundedTol = 0.1f;
	static bool isGrounded(RigidbodyComponent* rigidbody);

	void checkCollisions();
	void resolveCollisions();
	void positionalCorrection();
	void updatePhysics();

	static void AddRigidbody(RigidbodyComponent* rigidbody);
	void IntegrateBodies(float dT);

	static void Start();
	static void Awake();
	static void Update(float msec);
	static void LateUpdate(float msec);

private:
	std::map<CollisionPair, CollisionInfo> m_Collisions = std::map<CollisionPair, CollisionInfo>();
	std::vector<RigidbodyComponent*> m_RigidBodies = std::vector<RigidbodyComponent*>();
};

