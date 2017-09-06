#pragma once

#include "Timer.h"
#include <iostream>
#include <string>

class Gun
{
public:
	Gun(const int damageFar_in, const int damageNear_in, const int magazineSize_in, const float reloadTime_in, const float fireRate_in);
	void Update(const float deltaTime, const std::string& heroName);
	bool Shoot(const std::string& opponentName, const std::string& heroName);
	void Reload();
	int GetDamageNear() const;
	int GetDamageFar() const;
	bool HasBullets() const;
	void ResetReloadTimer();

private:
	const int damageFar;
	const int damageNear;
	const int magazineSize;
	int bulletsLeft;
	Timer reloadTimer;
	Timer cooldownTimer;
};