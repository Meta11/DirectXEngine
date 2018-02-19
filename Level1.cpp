#include "Level1.h"
#include "Graphics.h"

void Level1::Load()
{
	y = 0.0f;
	ySpeed = 0.0f;
}
void Level1::Unload() {}
void Level1::Update()
{
	ySpeed += 0.3f;
	y += ySpeed;

	if (y > 550)
	{
		y = 550.0f;
		ySpeed = -15.0f;
	}
}
void Level1::Render()
{
	gfx->clearScreen(0.0f, 0.0f, 0.0f);
	gfx->drawCircle(400.0f, y, 50.0f, 1.0f, 1.0f, 0.0f);
}