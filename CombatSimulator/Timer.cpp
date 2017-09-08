#include "Timer.h"

Timer::Timer(float limit_in)
	:
	mLimit(limit_in)
{}

bool Timer::limitReached()
{
	if (mCounter >= mLimit)
	{
		mCounter = 0.0f;
		return true;
	}
	return false;
}

void Timer::Update(float dt_in)
{
	mCounter += dt_in;
}

void Timer::Reset()
{
	mCounter = 0.0f;
}
