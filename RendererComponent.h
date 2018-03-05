#pragma once
#include "Component.h"
#include "Math.h"

class SpriteSheet;
class Entity;

class RendererComponent : public Component {
	SpriteSheet* gfx;
	Entity* parent;

public:
	void renderEntity(Vector3D position, float angle, int frame, int row);
	void setGraphics(SpriteSheet* graphics);
};
