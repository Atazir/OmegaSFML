#include "PhysicsManager.hpp"
//#include "RigidbodyComponent.hpp"

PhysicsManager pMan;

bool PhysicsManager::isGrounded(RigidbodyComponent * rigidbody)
{
	for each(RigidbodyComponent* rb in pMan.m_RigidBodies)
	{
		if (rb != rigidbody)
		{
			if (rigidbody->aabb.bLeft.x < rb->aabb.tRight.x
				&& rigidbody->aabb.tRight.x > rb->aabb.bLeft.x
				&& std::abs(rigidbody->aabb.bLeft.y - rb->aabb.tRight.y) <= pMan.groundedTol) {
				if (std::abs(rigidbody->currentVelocity.y) < pMan.groundedTol)
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
	pMan.m_RigidBodies.push_back(rigidbody);
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
