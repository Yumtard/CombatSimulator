#include "Gun.h"

Gun::Gun(const int damageFar_in, const int damageNear_in, const int magazineSize_in, 
	const float reloadTime_in, const float fireRate_in, const std::string& ownerName_in, const std::string name_in)
	:
	Weapon(fireRate_in, ownerName_in, name_in, damageNear_in, damageFar_in),
	magazineSize(magazineSize_in),
	bulletsLeft(magazineSize_in),
	reloadTimer(reloadTime_in)
{}

void Gun::Update(const float deltaTime)
{
	cooldownTimer.Update(deltaTime);

	if (!HasBullets())
	{
		reloadTimer.Update(deltaTime);

		if (reloadTimer.limitReached())
		{
			Reload();
			std::cout << ownerName << " reloaded his " << name << ".\n" << std::endl;
		}
	}
}

bool Gun::Attack(const std::string& targetName, const std::string& heroName)
{
	if (cooldownTimer.limitReached() && HasBullets())
	{
		--bulletsLeft;
		std::cout << heroName << " used his " << name << " and shot " << targetName << "." << std::endl;
		return true;
	}
	return false;
}

void Gun::Reload()
{
	bulletsLeft = magazineSize;
}

bool Gun::HasBullets() const
{
	return bulletsLeft > 0;
}

void Gun::Reset()
{
	reloadTimer.Reset();
	cooldownTimer.Reset();
}
