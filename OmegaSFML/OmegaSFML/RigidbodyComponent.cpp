#include "RigidbodyComponent.hpp"
#include "PhysicsManager.hpp"
//#include "TransformComponent.hpp"
//#include "SpriteComponent.hpp"

void RigidbodyComponent::Awake()
{
	
}

void RigidbodyComponent::Start()
{
	PhysicsManager::AddRigidbody(this);
}

void RigidbodyComponent::SetAABB()
{
	///Requires refactoring of code base to be properly executed.
	FloatRect getLocalBounds(boundingBox);
}

void RigidbodyComponent::Integrate(float dT)
{
	if (obeysGravity && !isGrounded())
	{
		AddForce(gravity);
	}
	else
	{
		if (currentVelocity.y < 0.05f)
		{
			currentVelocity.y = 0.0f;
		}
	}

	Vector2f acceleration = totalForces / mass;
	if (mass == 0)
	{
		acceleration = Vector2f(0.0f, 0.0f);
	}

	currentVelocity += acceleration * dT;

	//temp = TransformComponent::m_Position;
	temp += currentVelocity * dT;
	//TransformComponent::m_Position = temp;
	SetAABB();

	totalForces = Vector2f(0.0f, 0.0f);
}

bool RigidbodyComponent::isGrounded()
{
	grounded = PhysicsManager::isGrounded(this);
	return grounded;
}

void RigidbodyComponent::AddForce(Vector2f force)
{
	totalForces += force;
}

void RigidbodyComponent::Stop()
{

	currentVelocity = Vector2f(0.0f, 0.0f);
	totalForces = Vector2f(0.0f, 0.0f);

}
