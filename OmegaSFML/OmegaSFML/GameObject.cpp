#include "GameObject.hpp"

void GameObject::Awake() 
{
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Awake();
		std::cout << "GameObject Awake" << std::endl;
	}
	    for(std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end(); ++i) {
	        (*i)->Awake();
	    }
}

void GameObject::Start() 
{
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Start();
		std::cout << "GameObject Start" << std::endl;
	}
		for(std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end();    ++i) {
		    (*i)->Start();
		}
}

void GameObject::Update(float msec) 
{
	//if (m_Parent) { //This node has a parent...
	//	//worldTransform = m_Parent->worldTransform * transform;
	//}
	//else { //Root node, world transform is local transform!
	//	//worldTransform = ;
	//}
}

void GameObject::LateUpdate(float msec) 
{
	for (std::vector<BaseComponent*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) 
	{
		(*i)->LateUpdate();
		//std::cout << "GameObject LateUpdate" << std::endl;
	}
	for (std::vector<SpriteComponent*>::iterator i = m_Sprites.begin(); i != m_Sprites.end(); ++i) 
	{	
		(*i)->Draw();
		//std::cout << "SpriteComonent LateUpdate" << std::endl;
	}
		for(std::vector<GameObject*>::iterator i = m_Children.begin(); i != m_Children.end();    ++i) {
				(*i)->LateUpdate(msec);
		    }

	//Updates are being cycled for components.
	//std::cout << "The Components are updating." << std::endl;
}

void GameObject::AddComponent(BaseComponent* component, TransformComponent* transform, SpriteComponent* sprite)
{
	m_Components.push_back(component);
	m_Components.push_back(transform);
	m_Components.push_back(sprite);
	m_Sprites.push_back(sprite);
}

void GameObject::AddChild(GameObject* child) 
{
	m_Children.push_back(child);
}