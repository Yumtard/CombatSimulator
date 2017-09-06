#include "Timer.h"

Timer::Timer(float limit_in)
	:
	limit(limit_in)
{}

bool Timer::limitReached()
{
	if (counter >= limit)
	{
		counter = 0.0f;
		return true;
	}
	return false;
}

void Timer::Update(float deltaTime)
{
	counter += deltaTime;
}

void Timer::Reset()
{
	counter = 0.0f;
}
