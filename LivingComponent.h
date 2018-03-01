#pragma once
#include "Component.h"

class PhysicsComponent;
class RendererComponent;

class LivingComponent : public Component {
	PhysicsComponent* physics;
	RendererComponent* gfx;
	float timeToDie;
	float timer;
	
public:
	int hp;

	bool initialize();
	bool shutdown();
	void update();

	void setTimer(float time);
	void move();
	void attack();
	void die();

};
