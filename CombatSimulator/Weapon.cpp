#include "Weapon.h"

Weapon::Weapon(WeaponData* data_in)
	:
	mData(data_in),
	mCooldownTimer(data_in->cooldownTime)
{}

void Weapon::Update(const float dt_in)
{
	mCooldownTimer.Update(dt_in);
}

int Weapon::GetDamageFar() const
{
	return mData->damageFar;
}

int Weapon::GetDamageNear() const
{
	return mData->damageNear;
}

void Weapon::Reset()
{
	mCooldownTimer.Reset();
}

const char* Weapon::GetName() const
{
	return mData->name;
}

