#pragma once

#include "Timer.h"
#include "Weapon.h"
#include <iostream>
#include <string>

class Gun :
	public Weapon
{
public:
	Gun(const int damageFar_in, const int damageNear_in, const int magazineSize_in, 
		const float reloadTime_in, const float fireRate_in, const std::string& ownerName_in, const std::string name_in);
	virtual void Update(const float deltaTime) override;
	virtual bool Attack(const std::string& targetName, const std::string& heroName) override;
	void Reload();
	bool HasBullets() const;
	virtual void Reset() override;

private:
	const int magazineSize;
	int bulletsLeft;
	Timer reloadTimer;
};