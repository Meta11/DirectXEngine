#pragma once
#include "Clock.h"

class GameClock {
	
	static GameClock instance;
	Clock clock;
	
	GameClock() {};
	GameClock(const GameClock&);
	GameClock& operator=(const GameClock&);
public:
	static GameClock& getInstance();
	bool initialize();
	bool shutdown();
	void newFrame();
	float dt() const;
};

#define gameClock GameClock::getInstance()

