#include <stdio.h>
#include <iostream>
#include "GameObject.hpp"
#include <map>
#include <list>
#include <iterator>

class GameObjectManager
{
public:
	GameObjectManager();
	GameObject* CreateObject();

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);
private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};

