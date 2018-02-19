#pragma once
#include "GameLevel.h"

class Graphics;

class GameController {
	GameController() {}
	static GameLevel* currentLevel;
	static bool loading;
public:
	static void loadLevel(GameLevel* level);
	static void switchLevel(GameLevel* level);

	static void initialize();

	static void render();
	static void update();
};

