#pragma once

class Timer
{
public:
	Timer(float limit_in);
	bool limitReached();
	void Update(float dt_in);
	void Reset();

private:
	float mCounter = 0.0f;
	const float mLimit = 0.0f;
};