#include "Entity.h"
#include "Component.h"

Entity::Entity()
{
	numComponents = 0;
	orientation = 0;
}

void Entity::setPosition(float x, float y)
{
	position.x = x;
	position.y = y;
}

bool Entity::initialize()
{
	destroy = false;
	for (int i = 0; i < numComponents; i++)
		if (!components[i]->initialize())
			return false;
	return true;
}

bool Entity::shutdown()
{
	for (int i = 0; i < numComponents; i++)
		if (!components[i]->shutdown())
			return false;
	return true;
}

void Entity::addComponent(Component* component)
{
	components[numComponents++] = component;
	component->parent = this;
}

void Entity::update()
{
	for (int i = 0; i < numComponents; i++)
		components[i]->update();
}