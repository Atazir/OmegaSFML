#include "GameObjectManager.hpp"
#include <iostream>

using namespace std;

int GameObjectManager::nextObjectID = 0;


void GameObjectManager::Awake() 
{
	for (map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) 
	{
		(i->second)->Awake();
	}
}

void GameObjectManager::Start() 
{
	for (map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) 
	{
		(i->second)->Start();
	}
}

void GameObjectManager::Update(float msec) 
{
	for (map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) 
	{
		(i->second)->Update(msec);
	}
}

void GameObjectManager::LateUpdate(float msec) 
{
	for (map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) 
	{
		(i->second)->LateUpdate(msec);
	}
}

GameObject* GameObjectManager::CreateObject()
{
	GameObject* newObj = new GameObject(nextObjectID++);

	BaseComponent* baseComponent = new BaseComponent();
	TransformComponent* objTransform = new TransformComponent();
	SpriteComponent* objSprite = new SpriteComponent();
	newObj->AddComponent(baseComponent, objTransform, objSprite);

	m_Objects[newObj->GetObjectID()] = newObj;

	return newObj;
}
