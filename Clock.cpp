#include "Clock.h"

bool Clock::initialize()
{
	bool b = QueryPerformanceFrequency(&timeFrequency);
	if (!b)
		return false;
	return QueryPerformanceCounter(&lastStartTime);
}

bool Clock::shutdown() { return true; }

void Clock::start()
{
	QueryPerformanceCounter(&lastStartTime);
}

void Clock::stop()
{
	LARGE_INTEGER thisTime;
	QueryPerformanceCounter(&thisTime);

	LARGE_INTEGER delta;
	delta.QuadPart = thisTime.QuadPart - lastStartTime.QuadPart;
	deltaTime = (float)delta.QuadPart / timeFrequency.QuadPart;
}
void Clock::lap()
{
	stop();
	start();
}
float Clock::lastLapTime() const
{
	return deltaTime;
}