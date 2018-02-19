#pragma once
#include <wincodec.h>
#include "Graphics.h"

class SpriteSheet {
	Graphics* gfx;
	ID2D1Bitmap* bmp;
	int spriteWidth, spriteHeight;
	int spritesAcross;

public:
	SpriteSheet(const wchar_t* filename, Graphics* gfx);
	SpriteSheet(const wchar_t* filename, Graphics* gfx, int spriteWidth, int spriteHeight);
	~SpriteSheet();
	void draw();
	void draw(int index, int x, int y);
};

