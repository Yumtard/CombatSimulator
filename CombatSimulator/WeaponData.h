#pragma once

struct WeaponData
{
	int damageNear;
	int damageFar;
	int maxMagazineSize;
	float reloadTime;
	float cooldownTime;
	char* name;
	char* ownerName;
};