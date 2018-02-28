#pragma once
#include <wincodec.h>
#include "Renderer.h"
#include "Math.h"

class SpriteSheet {
	friend class RendererComponent;
	Renderer* gfx;
	ID2D1Bitmap* bmp;
	int spriteWidth, spriteHeight;
	int spritesAcross;

public:
	SpriteSheet(const wchar_t* filename, Renderer* gfx);
	SpriteSheet(const wchar_t* filename, Renderer* gfx, int spriteWidth, int spriteHeight);
	~SpriteSheet();
	void draw();
	void draw(Vector3D position, int index, int row);
};

