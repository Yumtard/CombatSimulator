#pragma once

class Timer
{
public:
	Timer() = default;
	Timer(float limit_in);
	bool limitReached();
	void Update(float deltaTime);
	void Reset();

private:
	float counter = 0.0f;
	const float limit = 0.0f;
};