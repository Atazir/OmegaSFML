#include "TransformComponent.hpp"

void TransformComponent::Awake()
{
	sf::Transform transform;
	//glLoadMatrixf(transform.getMatrix());
	sf::Transform mat4;
	//Model = glm::mat4(1.0f);
	//Model = glm::translate(Model, glm::vec3(m_Position.x, m_Position.y, m_Position.z));
	//Model = glm::rotate(Model, glm::radians(m_Rotation.x), X_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.y), Y_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.z), Z_AXIS);
	//Model = glm::scale(Model, glm::vec3(m_Scale.x, m_Scale.y, m_Scale.z));
	//transformMatrix = Model;
}

void TransformComponent::Start()
{

}

void TransformComponent::Update()
{
	// Change later to only happen when my transform changes.
	//glm::mat4 Model;
	//Model = glm::mat4(1.0f);
	//Model = glm::translate(Model, glm::vec3(m_Position.x, m_Position.y, m_Position.z));
	//Model = glm::rotate(Model, glm::radians(m_Rotation.x), X_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.y), Y_AXIS);
	//Model = glm::rotate(Model, glm::radians(m_Rotation.z), Z_AXIS);
	//Model = glm::scale(Model, glm::vec3(m_Scale.x, m_Scale.y, m_Scale.z));
	//transformMatrix = Model;
}

void TransformComponent::LateUpdate()
{

}