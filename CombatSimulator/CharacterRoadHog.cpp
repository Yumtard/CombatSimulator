#include "CharacterRoadHog.h"

CharacterRoadHog::CharacterRoadHog(CharacterData* data_in)
	:
	Character(data_in),
	mSpecialAttackTimer(data_in->specialAttackTime),
	mWeaponSwitchTimer(data_in->weaponSwitchTime)
{}

void CharacterRoadHog::Update(const float dt_in)
{
	if (!IsDead())
	{
		mData->weapons[mCurWeapon]->Update(dt_in);
		mSpecialAttackTimer.Update(dt_in);
		mWeaponSwitchTimer.Update(dt_in);

		Attack();

		if (mWeaponSwitchTimer.limitReached())
		{
			SwitchWeapon();
		}

		if (!mCloseCombat && mSpecialAttackTimer.limitReached())
		{
			SpecialAttack();
		}
	}
}

void CharacterRoadHog::SpecialAttack()
{
	std::cout << mData->name << " used his special hook skill to get into close combat.\n" << std::endl;
	mCloseCombat = true;
	pTarget->IsCloseCombat();
}





