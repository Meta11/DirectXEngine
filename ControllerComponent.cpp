#include "ControllerComponent.h"
#include "PhysicsComponent.h"
#include "Math.h"
#include "KeyInput.h"
#include "MyMenuChoice.h"

bool ControllerComponent::initialize()
{
	this->physics = getParent()->getComponent<PhysicsComponent>();
	velocity = 200.0f;

	return physics != 0;
}
void ControllerComponent::update()
{
	if (input.actionsHot(Up))
		physics->setVelocity(0, -velocity);
	else if (input.actionsHot(Down))
		physics->setVelocity(0, velocity);
	else if (input.actionsHot(Left))
		physics->setVelocity(-velocity, 0);
	else if (input.actionsHot(Right))
		physics->setVelocity(velocity, 0);
	else if (input.actionsHot(Focus))
		physics->setVelocity(velocity, 0);
	else if (input.actionsHot(Shoot))
		physics->setVelocity(velocity, 0);
	else if (input.actionsHot(Bomb))
		physics->setVelocity(velocity, 0);
	else if (input.actionsHot(Pause))
		physics->setVelocity(velocity, 0);
	else
		physics->setVelocity(0, 0);
}