#include "BaseComponent.hpp"

BaseComponent::BaseComponent()
{
	std::cout << "This Added a Component." << std::endl;
	//TransformComponent* myTransform = new TransformComponent();
	//AddTransform(myTransform);
}

BaseComponent::~BaseComponent()
{
	
}

//void BaseComponent::AddTransform(TransformComponent* transform)
//{
//	std::cout << "This Added a transform." << std::endl;
//}

