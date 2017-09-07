#include "CharacterRoadHog.h"

CharacterRoadHog::CharacterRoadHog(const std::string& name_in, const int health_in, 
	float specialAttackTimeLimit, float weaponSwitchTimeLimit)
	:
	Character(name_in, health_in),
	specialAttackTimer(specialAttackTimeLimit),
	weaponSwitchTimer(weaponSwitchTimeLimit)
{}

void CharacterRoadHog::Update(const float deltaTime)
{
	if (!IsDead())
	{
		weapons[curWeapon]->Update(deltaTime);
		specialAttackTimer.Update(deltaTime);
		weaponSwitchTimer.Update(deltaTime);

		Attack();

		if (weaponSwitchTimer.limitReached())
		{
			SwitchWeapon();
		}

		if (!closeCombat && specialAttackTimer.limitReached())
		{
			SpecialAttack();
		}
	}
}

void CharacterRoadHog::SpecialAttack()
{
	std::cout << name << " used his special hook skill to get into close combat.\n" << std::endl;
	closeCombat = true;
	pTarget->IsCloseCombat();
}





