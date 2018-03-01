#pragma once
#include "PhysicsComponent.h"
#include "Renderer.h"
#include "RendererComponent.h"
#include "AnimationComponent.h"
#include "LivingComponent.h"
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
	Entity backgroundEntity;
	Entity playerEntity;
	Entity* enemyEntity;
	SpriteSheet* backgroundGraphics;
	SpriteSheet* playerGraphics;
	SpriteSheet* enemyGraphics;
	PhysicsComponent playerPhysicsComponent;
	RendererComponent backgroundRenderer;
	RendererComponent playerRenderer;
	AnimationComponent playerAnimationComponent;

public:
	static void initialize(Renderer* graphics) { gfx = graphics; }

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

