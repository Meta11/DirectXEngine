#pragma once
#include "Component.h"
#include "Math.h"

class PhysicsComponent : public Component {
public:
	PhysicsComponent() { velocity = Vector3D(0, 0); }
	Vector3D velocity;
	Vector3D acceleration;
	float angularVelocity;
	void update();
	void setAcceleration(float x, float y);
	void setVelocity(float x, float y);
	void setAngularVelocity(float omega);
};