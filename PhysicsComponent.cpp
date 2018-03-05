#include "PhysicsComponent.h"
#include "Entity.h"
#include "GameClock.h"

void PhysicsComponent::update()
{
	velocity += acceleration * gameClock.dt();
	getParent()->position += velocity * gameClock.dt();
	getParent()->orientation += angularVelocity * gameClock.dt();
}

void PhysicsComponent::setAcceleration(float x, float y)
{
	acceleration.x = x;
	acceleration.y = y;
	acceleration.z = 0; 
}

void PhysicsComponent::setVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
	velocity.z = 0;
}

void PhysicsComponent::setAngularVelocity(float omega)
{
	angularVelocity = omega;
}