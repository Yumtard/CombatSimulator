#pragma once

#include "Timer.h"
#include "Weapon.h"
#include <string>
#include <iostream>
#include <random>
#include <fstream>
#include <vector>

class TauntPole :
	public Weapon
{
public:
	TauntPole(float cooldown, const std::string& ownerName_in, const std::string name_in);
	virtual bool Attack(const std::string& targetName, const std::string& heroName) override;

private:
	std::random_device rd;
	std::mt19937 rng;
	std::vector<std::string> insults;
};