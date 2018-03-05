#include "RendererComponent.h"
#include "SpriteSheet.h"

void RendererComponent::setGraphics(SpriteSheet* graphics)
{
	this->gfx = graphics;
}

void RendererComponent::renderEntity(Vector3D position, float angle, int frame = 0, int row = 0)
{
	gfx->draw(position, angle, frame, row);
}



