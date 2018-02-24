#include "GameObject.hpp"

void GameObject::Awake() 
{
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Awake();
	}
	//    for(std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i) {
	//        (*i)->Awake();
	//    }
}

void GameObject::Start() 
{
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Start();
	}
	//    for(std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i) {
	//        (*i)->Start();
	//    }
}

void GameObject::Update(float msec) 
{
	
}

void GameObject::LateUpdate(float msec) 
{
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->LateUpdate();
	}
	//    for(std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i) {
	//        (*i)->LateUpdate(msec);
	//    }
}

void GameObject::AddComponent(BaseComponent* component)
{
	m_Components.push_back(component);
}

void GameObject::AddChild(GameObject* child) 
{
	m_Children.push_back(child);
}