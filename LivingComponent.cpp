#include "LivingComponent.h"
#include "GameClock.h"
#include "PhysicsComponent.h"

bool LivingComponent::initialize()
{
	timer = 0;
	hp = 0;
	physics = getParent()->getComponent<PhysicsComponent>();
	if (physics == nullptr)
		return false;
	return true;
}

bool LivingComponent::shutdown()
{
	return true;
}

void LivingComponent::update()
{
	if (timeToDie > 0)
	{
		timer += gameClock.dt();
		if (timer > timeToDie)
		{
			die();
		}
	}
}


void LivingComponent::setTimer(float time)
{
	timeToDie = time;
}

void LivingComponent::move()
{

}

void LivingComponent::attack()
{

}

void LivingComponent::die()
{
	getParent()->destroy = true;
}