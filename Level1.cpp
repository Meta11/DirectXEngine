#include "Level1.h"
#include "Entity.h"
#include "Renderer.h"

void Level1::Load()
{
	frame = 0;
	SpriteSheet* enemyGraphics = new SpriteSheet(L"prueba.png", gfx, 64, 64);

	for (int i = 0; i < 6; i++)
	{
		enemyEntity = new Entity();
		//PhysicsComponent
		enemyEntity->addComponent(new PhysicsComponent());
		enemyEntity->getComponent<PhysicsComponent>()->setAcceleration(0, i*3.0f);
		//GraphicsComponent
		enemyEntity->setPosition(i*64, i*64);
		enemyEntity->addComponent(new RendererComponent());
		enemyEntity->getComponent<RendererComponent>()->setGraphics(enemyGraphics);
		//AnimationComponent
		enemyEntity->addComponent(new AnimationComponent());
		enemyEntity->getComponent<AnimationComponent>()->setFramesData(4);
		enemyEntity->initialize();
		entities.push_back(enemyEntity);
	}

	//GraphicsComponent
	playerEntity.setPosition(350, 200);
	playerGraphics = new SpriteSheet(L"Reimu.png", gfx, 32, 48);
	playerRenderer.setGraphics(playerGraphics);
	playerEntity.addComponent(&playerRenderer);
	//PhysicsComponent
	playerEntity.addComponent(&playerPhysicsComponent);
	//AnimationComponent
	playerAnimationComponent.setFramesData(8);
	playerEntity.addComponent(&playerAnimationComponent);
	playerEntity.initialize();
	entities.push_back(&playerEntity);

}
void Level1::Unload()
{
	for (auto& ent : entities)
	{
		delete ent;
	}
}
void Level1::Update()
{
	gameClock.newFrame();
	std::list<Entity*>::iterator it; 
	it = entities.begin();

	for (auto& ent : entities)
	{
		if (ent->destroy)
		{
			entities.erase(it);
		}
		else
		{
			ent->update();
			it++;
		}
	}
}
void Level1::Render()
{
	gfx->clearScreen(0.0f, 0.0f, 0.0f);
	for (auto& entity : entities)
	{
		entity->getComponent<RendererComponent>()->
			renderEntity(entity->position, (frame) / entity->getComponent<AnimationComponent>()->animationSpeed %
				entity->getComponent<AnimationComponent>()->numFrames, entity->getComponent<AnimationComponent>()->animationRow);
	}
	frame++;
}