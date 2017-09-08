#pragma once

#include "Timer.h"
#include "WeaponData.h"
#include <iostream>

class Weapon
{
public:
	Weapon(WeaponData* data_in);
	virtual void Update(const float dt_in);
	virtual bool Attack(const char* targetName_in, const char* ownerName_in) = 0;
	int GetDamageFar() const;
	int GetDamageNear() const;
	virtual void Reset();
	const char* GetName() const;

protected:
	WeaponData* mData = nullptr;
	Timer mCooldownTimer;
};