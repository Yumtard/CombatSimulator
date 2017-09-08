#pragma once

#include "Timer.h"
#include "Weapon.h"
#include "WeaponData.h"
#include <iostream>
#include <random>
#include <fstream>
#include <vector>

class TauntPole :
	public Weapon
{
public:
	TauntPole(WeaponData* data_in);
	virtual bool Attack(const char* targetName_in, const char* ownerName_in) override;

private:
	std::random_device rd;
	std::mt19937 rng;
	std::vector<std::string> mInsults;
};