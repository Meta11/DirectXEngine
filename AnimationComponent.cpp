#include "AnimationComponent.h"
#include "PhysicsComponent.h"

float animationSpeed;
int animationRow;

bool AnimationComponent::initialize()
{
	animationRow = 0;
	animationSpeed = 10;
	physics = getParent()->getComponent<PhysicsComponent>();
	if (physics == nullptr)
		return false;
	return true;
}

bool AnimationComponent::shutdown()
{
	return true;
}

void AnimationComponent::update()
{
	if (physics->velocity.x < 0)
		animationRow = 1;
	if (physics->velocity.x > 0)
		animationRow = 2;
	else
		animationRow = 0;
}

void AnimationComponent::setFramesData(int animationFrames)
{
	numFrames = animationFrames;
}