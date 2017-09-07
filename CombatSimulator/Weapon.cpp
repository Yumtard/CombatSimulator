#include "Weapon.h"

Weapon::Weapon(float cooldown, const std::string& ownerName_in, const std::string name_in)
	:
	cooldownTimer(cooldown),
	ownerName(ownerName_in),
	name(name_in)
{}

Weapon::Weapon(float cooldown, const std::string & ownerName_in, const std::string name_in, int damageNear_in, int damageFar_in)
	:
	cooldownTimer(cooldown),
	ownerName(ownerName_in),
	damageNear(damageNear_in),
	damageFar(damageFar_in),
	name(name_in)
{}

void Weapon::Update(const float deltaTime)
{
	cooldownTimer.Update(deltaTime);
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

