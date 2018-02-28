#include "GameController.h"

GameLevel* GameController::currentLevel;
bool GameController::loading;

void GameController::loadLevel(GameLevel* level)
{
	loading = true;
	currentLevel = level;
	currentLevel->Load(); 
	loading = false;
}
void GameController::switchLevel(GameLevel* level)
{
	loading = true;
	currentLevel->Unload();
	delete currentLevel;
	currentLevel = level;
	loading = false;
}

void GameController::initialize()
{
	loading = true;
	currentLevel = nullptr;
}

void GameController::render()
{
	if (loading)
		return;
	currentLevel->Render();
}
void GameController::update()
{
	if (loading)
		return;
	currentLevel->Update();
}