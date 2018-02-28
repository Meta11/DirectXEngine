#pragma once
#include "Component.h"

class PhysicsComponent;

class AnimationComponent : public Component {
	
public:
	PhysicsComponent* physics;
	int animationSpeed;
	int animationRow;
	int numFrames;

	bool initialize();
	bool shutdown();
	void update();
	void setFramesData(int animationFrames);
};
