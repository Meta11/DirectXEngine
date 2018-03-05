#pragma once
#include <wincodec.h>
#include "Math.h"
#include "Renderer.h"

class RendererComponent;

class SpriteSheet {
	friend class RendererComponent;
	Renderer* gfx;
	RendererComponent* renderComponent;
	ID2D1Bitmap* bmp;
	int spriteWidth, spriteHeight;
	int spritesAcross;

public:
	D2D1::Matrix3x2F position;

	SpriteSheet(const wchar_t* filename, Renderer* gfx);
	SpriteSheet(const wchar_t* filename, Renderer* gfx, int spriteWidth, int spriteHeight);
	~SpriteSheet();
	void draw();
	void draw(Vector3D position, float angle, int index, int row);
};

