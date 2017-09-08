#include "Character.h"

Character::Character(CharacterData* data_in)
{
	mData = data_in;
	mHealth = mData->maxHealth;
}

void Character::Update(const float dt_in)
{
	if (!IsDead())
	{
		mData->weapons[mCurWeapon]->Update(dt_in);
		Attack();
	}
}

int Character::GetHealth() const
{
	return mHealth;
}

void Character::IsCloseCombat()
{
	mCloseCombat = true;
}

void Character::TakeDamage(const int damage_in)
{
	mHealth -= damage_in;

	if (mHealth < 0)
	{
		mHealth = 0;
	}
	std::cout << mData->name << " took " <<  damage_in <<" damage\n"
		<< mData->name << " has " << mHealth << " HP left.\n\n";
}

const char* Character::GetName() const
{
	return mData->name;
}

bool Character::IsDead() const
{
	return mHealth <= 0;
}

void Character::AddWeapon(Weapon * weapon_in)
{
	if (mNumWeapons != mData->maxNumWeapons)
	{
		mNumWeapons++;
		mData->weapons.push_back(weapon_in);
	}
}

void Character::SwitchWeapon()
{
	mData->weapons[mCurWeapon]->Reset();

	if ((mCurWeapon + 1) == mNumWeapons)
	{
		mCurWeapon = 0;
	}
	else
	{
		mCurWeapon++;
	}
}

void Character::SetTarget(Character * pTarget_in)
{
	pTarget = pTarget_in;
}

void Character::Attack()
{
	if (mCloseCombat)
	{
		const int dmgNear = mData->weapons[mCurWeapon]->GetDamageNear();
		if (mData->weapons[mCurWeapon]->Attack(pTarget->GetName(), mData->name) && dmgNear > 0)
		{
			pTarget->TakeDamage(dmgNear);
		}
	}
	else
	{
		const int dmgFar = mData->weapons[mCurWeapon]->GetDamageFar();
		if (mData->weapons[mCurWeapon]->Attack(pTarget->GetName(), mData->name) && dmgFar > 0)
		{
			pTarget->TakeDamage(dmgFar);
		}
	}
}

