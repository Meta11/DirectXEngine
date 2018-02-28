#pragma once
#include "Math.h"

class Component;

class Entity {
	static const int NUM_MAX_COMPONENTS = 5;
	Component* components[NUM_MAX_COMPONENTS];
	int numComponents;
	float timer;
public:
	Entity();
	Vector3D position;
	bool destroy;
	bool initialize();
	bool shutdown();
	void setPosition(float x, float y);
	void addComponent(Component* component);
	void update();

	template<class T>
	T* getComponent() const;
};

template<class T>
T* Entity::getComponent() const
{
	for (int i = 0; i < numComponents; i++)
	{
		T* ret = dynamic_cast<T*>(components[i]);
		if (ret != nullptr)
			return ret;
	}
	return 0;
}
