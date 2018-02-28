#include "PhysicsComponent.h"
#include "Entity.h"
#include "GameClock.h"

void PhysicsComponent::update()
{
	velocity += acceleration * gameClock.dt();
	//acceleration = Vector3D(0, 0);
	getParent()->position += velocity * gameClock.dt();
}

void PhysicsComponent::setAcceleration(float x, float y)
{
	getParent()->getComponent<PhysicsComponent>()->acceleration.x = x;
	getParent()->getComponent<PhysicsComponent>()->acceleration.y = y;
	getParent()->getComponent<PhysicsComponent>()->acceleration.z = 0; 
}