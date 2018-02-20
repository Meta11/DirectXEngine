#include "Level1.h"
#include "SpriteSheet.h"
#include "Graphics.h"

void Level1::Load()
{
	y = 0.0f;
	ySpeed = 0.0f;
	sprite1 = new SpriteSheet(L"prueba.png", gfx, 64, 64);
	frame = 0;
}
void Level1::Unload()
{
	delete sprite1;
}
void Level1::Update()
{
	ySpeed += 0.3f;
	y += ySpeed;
	xSpeed += 0.3f;
	x += ySpeed;

	if (y > 550)
	{
		y = 550.0f;
		ySpeed = -15.0f;
	}
	frame++;
}
void Level1::Render()
{
	gfx->clearScreen(0.0f, 0.0f, 0.0f);
	gfx->drawCircle(400.0f, y, 50.0f, 1.0f, 1.0f, 0.0f);
	sprite1->draw((frame / 15) % 4, 368, y - 32);
}