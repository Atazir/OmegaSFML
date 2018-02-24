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

private:
	int m_UniqueID;
	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	std::vector<BaseComponent*> m_Components;
};
