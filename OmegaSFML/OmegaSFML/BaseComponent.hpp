#pragma once
class BaseComponent
{
public:
	BaseComponent();
	virtual void Awake() {}
	virtual void Start() {}
	virtual void Update() {}
	virtual void LateUpdate() {}
};

