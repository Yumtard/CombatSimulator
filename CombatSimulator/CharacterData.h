#pragma once

#include "Weapon.h"
#include<vector>

struct CharacterData
{
	int maxHealth;
	char* name = nullptr;
	std::vector<Weapon*> weapons;
	int maxNumWeapons; 
	float specialAttackTime;
	float weaponSwitchTime;
};