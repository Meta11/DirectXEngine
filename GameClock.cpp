#include "GameClock.h"

GameClock GameClock::instance;

GameClock& GameClock::getInstance() { return instance; }

bool GameClock::initialize()
{
	return clock.initialize();
}

bool GameClock::shutdown()
{
	return clock.initialize();
}

void GameClock::newFrame()
{
	return clock.lap();
}
float GameClock::dt() const
{
	return clock.lastLapTime();
}