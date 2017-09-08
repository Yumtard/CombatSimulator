#pragma once

#include "Timer.h"
#include "Weapon.h"
#include <iostream>

class Gun :
	public Weapon
{
public:
	Gun(WeaponData* data_in);
	virtual void Update(const float dt_in) override;
	virtual bool Attack(const char* targetName_in, const char* ownerName_in) override;
	void Reload();
	bool HasBullets() const;
	virtual void Reset() override;

private:
	int mBulletsLeft;
	Timer mReloadTimer;
};