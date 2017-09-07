#include "Weapon.h"

Weapon::Weapon(float cooldown, const std::string& ownerName_in)
	:
	cooldownTimer(cooldown),
	ownerName(ownerName_in)
{}

Weapon::Weapon(float cooldown, const std::string & ownerName_in, int damageNear_in, int damageFar_in)
	:
	cooldownTimer(cooldown),
	ownerName(ownerName_in),
	damageNear(damageNear_in),
	damageFar(damageFar_in)
{}

void Weapon::Update(const float deltaTime)
{
	cooldownTimer.Update(deltaTime);
}

bool Weapon::Attack(const std::string& targetName, const std::string& heroName)
{
	if (cooldownTimer.limitReached())
	{
		std::cout << heroName << " shot....Phew! phew! " << targetName << " took damage." << std::endl;
		return true;
	}
	return false;
}

int Weapon::GetDamageFar() const
{
	return damageFar;
}

int Weapon::GetDamageNear() const
{
	return damageNear;
}

void Weapon::Reset()
{
	cooldownTimer.Reset();
}

