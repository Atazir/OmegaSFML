#include "PhysicsManager.hpp"
#include "RigidbodyComponent.hpp"

bool PhysicsManager::isGrounded(RigidbodyComponent * rigidbody)
{
	for each(RigidbodyComponent* rb in m_Rigidbodies)
	{
		if (rb != rigidbody)
		{
			if (rigidBody.aabb.bLeft.x < rb.aabb.tRight.x
				&& rigidBody.aabb.tRight.x > rb.aabb.bLeft.x
				&& Mathf.Abs(rigidBody.aabb.bLeft.y - rb.aabb.tRight.y) <= groundedTol) {
				if (Mathf.Abs(rigidBody.currentVelocity.y) < groundedTol)
					return true;
			}
		}
	}
	return false;
}

void PhysicsManager::checkCollisions()
{

}

void PhysicsManager::resolveCollisions()
{

}

void PhysicsManager::positionalCorrection()
{

}

void PhysicsManager::updatePhysics()
{

}

void PhysicsManager::AddRigidbody(RigidbodyComponent* rigidbody)
{
	m_RigidBodies.push_back(rigidbody);
}

void PhysicsManager::IntegrateBodies(float dT)
{
	for each (RigidbodyComponent* rb in m_RigidBodies)
	{
		rb->Integrate(dT);
	}
}

void PhysicsManager::Start()
{

}

void PhysicsManager::Awake()
{

}

void PhysicsManager::Update(float msec)
{

}

void PhysicsManager::LateUpdate(float msec)
{

}
