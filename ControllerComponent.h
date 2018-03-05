#pragma once
#include "Component.h"

class PhysicsComponent;
class ControllerComponent : public Component {
	PhysicsComponent* physics;
	float velocity;
public:
	bool initialize();
	void update();
};