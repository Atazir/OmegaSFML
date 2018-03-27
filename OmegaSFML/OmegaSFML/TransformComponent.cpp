#include "TransformComponent.hpp"

TransformComponent::TransformComponent()
{
	AddTransform(m_Transform);
	std::cout << "Transform added properly." << std::endl;
}

void TransformComponent::Awake()
{
	m_Transform.getMatrix(); ///Gets the default 4x4 Matrix
	m_Transform.translate(m_Position.x, m_Position.y); ///Default Translation
	m_Transform.rotate(0); ///Default Rotation
	m_Transform.scale(1,1); ///Default Scale

	transformMatrix.getMatrix(); ///Gets the 4x4 matrix for the world transform
	transformMatrix = m_Transform; ///Makes the objects world transform the same as the objects transform.

	/*sf::Transform mat4 Model;
	//Model = glm::translate(Model, glm::vec3(m_Position.x, m_Position.y, m_Position.z));
	//Model = glm::rotate(Model, glm::radians(m_Rotation.x), X_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.y), Y_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.z), Z_AXIS);
	//Model = glm::scale(Model, glm::vec3(m_Scale.x, m_Scale.y, m_Scale.z));
	transformMatrix = Model;*/

	///Testing Debugs
	//std::cout << m_Position.x << std::endl;
	//std::cout << m_Position.y << std::endl;
	//std::cout << "Transform component is awake" << std::endl;
}

void TransformComponent::Start()
{

}

void TransformComponent::Update()
{
	//std::cout << "The Transform component is updating frequently." << std::endl;
	// Change later to only happen when my transform changes.
	//glm::mat4 Model;
	//Model = glm::mat4(1.0f);
	//Model = glm::translate(Model, glm::vec3(m_Position.x, m_Position.y, m_Position.z));
	//Model = glm::rotate(Model, glm::radians(m_Rotation.x), X_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.y), Y_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.z), Z_AXIS);
	//Model = glm::scale(Model, glm::vec3(m_Scale.x, m_Scale.y, m_Scale.z));
	//transformMatrix = Model;
	if (!updateHappening)
	{
		std::cout << "The Transform component is Updating frequently." << std::endl;
		updateHappening = true;
	}
}

void TransformComponent::LateUpdate()
{
	if (!lateUpdateHappening)
	{
		std::cout << "The Transform component is LateUpdating frequently." << std::endl;
		lateUpdateHappening = true;
	}
	
}

void TransformComponent::AddTransform(sf::Transform transform)
{
	std::cout << "This Added a Transform." << std::endl;
}