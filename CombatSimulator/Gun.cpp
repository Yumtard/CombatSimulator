#include "Gun.h"

Gun::Gun(const int damageFar_in, const int damageNear_in, const int magazineSize_in, const float reloadTime_in, const float fireRate_in)
	:
	damageFar(damageFar_in),
	damageNear(damageNear_in),
	magazineSize(magazineSize_in),
	bulletsLeft(magazineSize_in),
	reloadTimer(reloadTime_in),
	cooldownTimer(fireRate_in)
{}

void Gun::Update(const float deltaTime, std::string& heroName)
{
	cooldownTimer.Update(deltaTime);

	if (!HasBullets())
	{
		reloadTimer.Update(deltaTime);

		if (reloadTimer.limitReached())
		{
			Reload();
			std::cout << heroName << " reloaded.\n" << std::endl;
		}
	}
}

bool Gun::Shoot(const std::string& opponentName, const std::string& heroName)
{
	if (cooldownTimer.limitReached() && HasBullets())
	{
		--bulletsLeft;
		std::cout << heroName << " shot " << opponentName << std::endl;
		return true;
	}
	
	return false;
}

void Gun::Reload()
{
	bulletsLeft = magazineSize;
}

int Gun::GetDamageNear() const
{
	return damageNear;
}

int Gun::GetDamageFar() const
{
	return damageFar;
}

bool Gun::HasBullets() const
{
	return bulletsLeft > 0;
}

void Gun::ResetReloadTimer()
{
	reloadTimer.Reset();
}
