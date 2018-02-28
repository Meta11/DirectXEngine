#pragma once
#include "PhysicsComponent.h"
#include "Renderer.h"
#include "RendererComponent.h"
#include "AnimationComponent.h"
#include "SpriteSheet.h"
#include <list>
#include "Entity.h"
#include "GameClock.h"

class Renderer;

class GameLevel {
	friend class Renderer;
protected:
	static Renderer* gfx;
	std::list<Entity*> entities;
	Entity playerEntity;
	Entity* enemyEntity;
	PhysicsComponent playerPhysicsComponent;
	RendererComponent playerRenderer;
	AnimationComponent playerAnimationComponent;
	SpriteSheet* playerGraphics;

public:
	static void initialize(Renderer* graphics) { gfx = graphics; }

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

