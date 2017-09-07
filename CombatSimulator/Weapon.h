#pragma once

#include "Timer.h"
#include <string>
#include <iostream>

class Weapon
{
public:
	Weapon(float cooldown, const std::string& ownerName_in);
	Weapon(float cooldown, const std::string& ownerName_in, int damageNear_in, int damageFar_in);
	virtual void Update(const float deltaTime);
	virtual bool Attack(const std::string& targetName, const std::string& heroName) = 0;
	int GetDamageFar() const;
	int GetDamageNear() const;
	virtual void Reset();

protected:
	Timer cooldownTimer;
	const std::string& ownerName;
	int damageNear = 0;
	int damageFar = 0;

};