#include <stdio.h>
#include "BaseComponent.hpp"
#include "TransformComponent.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <iterator>


class GameObject
{
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) {}

	int GetObjectID() const { return m_UniqueID; }

	void AddComponent(BaseComponent* component);

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

	void SetParent(GameObject& parent) { m_Parent = &parent; }
	void AddChild(GameObject* child);

	TransformComponent transform; //This objects local transform

private:
	int m_UniqueID;

	GameObject* m_Parent;
	std::vector<GameObject*> m_Children; //A vector using this gameObject that lists its children (transform component, rigidbody, bounding box, etc)

	sf::Transform worldTransform;
	std::vector<BaseComponent*> m_Components;
};
