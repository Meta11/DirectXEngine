#pragma once
#include "SpriteSheet.h"
class Graphics;

class GameLevel {
protected:
	static Graphics* gfx;

public:
	static void initialize(Graphics* graphics) { gfx = graphics; }

	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

