#include "Level1.h"
#include "Entity.h"
#include "Renderer.h"

void Level1::Load()
{
	frame = 0;

	backgroundGraphics = new SpriteSheet(L"stage1.png", gfx, 512, 512);
	playerGraphics = new SpriteSheet(L"Reimu.png", gfx, 32, 48);
	enemyGraphics = new SpriteSheet(L"Enemies.png", gfx, 64, 64);

	//Background
	backgroundEntity.setPosition(50, 50);
	backgroundRenderer.setGraphics(backgroundGraphics);
	backgroundEntity.addComponent(&backgroundRenderer);
	backgroundEntity.initialize();

	//Player GraphicsComponent
	playerEntity.setPosition(350, 200);
	playerRenderer.setGraphics(playerGraphics);
	playerEntity.addComponent(&playerRenderer);
	//Player PhysicsComponent
	playerEntity.addComponent(&playerPhysicsComponent);
	//Player ControllerComponent
	playerEntity.addComponent(&playerControllerComponent);
	//Player AnimationComponent
	playerAnimationComponent.setFramesData(8);
	playerEntity.addComponent(&playerAnimationComponent);
	//Player LivingComponent
	playerEntity.initialize();
	entities.push_back(&playerEntity);
	
	for (int i = 0; i < 6; i++)
	{
		enemyEntity = new Entity();
		//PhysicsComponent
		enemyEntity->addComponent(new PhysicsComponent());
		enemyEntity->getComponent<PhysicsComponent>()->setAcceleration(0, i*3.0f);
		enemyEntity->getComponent<PhysicsComponent>()->setAngularVelocity(360.0f);
		//GraphicsComponent
		enemyEntity->setPosition(i*64, i*64);
		enemyEntity->addComponent(new RendererComponent());
		enemyEntity->getComponent<RendererComponent>()->setGraphics(enemyGraphics);
		//AnimationComponent
		enemyEntity->addComponent(new AnimationComponent());
		enemyEntity->getComponent<AnimationComponent>()->setFramesData(4);
		//Player LivingComponent
		enemyEntity->addComponent(new LivingComponent());
		enemyEntity->getComponent<LivingComponent>()->setTimer(10.0f);
		enemyEntity->initialize();
		entities.push_back(enemyEntity);
	}

}
void Level1::Unload()
{
	for (auto& ent : entities)
		ent->shutdown();

	entities.clear();
}
void Level1::Update()
{
	gameClock.newFrame();
	std::list<Entity*>::iterator it = entities.begin(); 

	while(it != entities.end())
	{
		if ((*it)->destroy)
		{
			(*it)->shutdown();
			entities.erase(it++);
		}
		else
		{
			(*it)->update();
			++it;
		}
	}
}
void Level1::Render()
{
	gfx->clearScreen(0.0f, 0.0f, 0.0f);

	backgroundEntity.getComponent<RendererComponent>()->renderEntity(backgroundEntity.position, 0, 0, 0);

	for (auto& entity : entities)
	{
		entity->getComponent<RendererComponent>()->
			renderEntity(entity->position, entity->orientation, (frame) / entity->getComponent<AnimationComponent>()->animationSpeed %
				entity->getComponent<AnimationComponent>()->numFrames, entity->getComponent<AnimationComponent>()->animationRow);
	}
	frame++;
}