#pragma once

#include "Timer.h"
#include <string>
#include <iostream>
#include <random>

class TauntPole
{
public:
	TauntPole(float cooldown);
	void Update(float deltaTime, const std::string& heroName);
	void Attack(const std::string& heroName);

private:
	const std::string name = "Taunt Pole";
	std::random_device rd;
	std::mt19937 rng;
	Timer cooldownTimer;
};