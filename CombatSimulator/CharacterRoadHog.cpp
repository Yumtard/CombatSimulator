#include "CharacterRoadHog.h"

CharacterRoadHog::CharacterRoadHog(const std::string& name_in, const int health_in, Gun & rScrapGun_in, TauntPole& rTauntPole_in, 
	float specialAttackTimeLimit, float weaponSwitchTimeLimit)
	:
	Character(name_in, health_in),
	specialAttackTimer(specialAttackTimeLimit),
	rScrapGun(rScrapGun_in),
	tauntPole(rTauntPole_in),
	weaponSwitchTimer(weaponSwitchTimeLimit)
{}

void CharacterRoadHog::Update(const float deltaTime)
{
	if (!IsDead())
	{
		if (weaponSwitchTimer.limitReached())
		{
			SwitchWeapon(deltaTime);
		}

		switch (weapon)
		{
		case _ScrapGun:
			rScrapGun.Update(deltaTime, name);
			break;

		case _TauntPole:
			tauntPole.Update(deltaTime, name);
			break;
		}

		if (!closeCombat)
		{
			SpecialAttack();
		}
		
		specialAttackTimer.Update(deltaTime);
		weaponSwitchTimer.Update(deltaTime);
		Attack();
	}
}

void CharacterRoadHog::SpecialAttack()
{
	if (specialAttackTimer.limitReached())
	{
		std::cout << name << " used his special hook skill to get into close combat.\n" << std::endl;
		closeCombat = true;
		pOpponent->IsCloseCombat();
	}
}

void CharacterRoadHog::Attack()
{
	switch (weapon)
	{
	case _ScrapGun:
		if (rScrapGun.Shoot(pOpponent->GetName(), name))
		{
			if (closeCombat)
			{
				pOpponent->TakeDamage(rScrapGun.GetDamageNear());
			}
			else
			{
				pOpponent->TakeDamage(rScrapGun.GetDamageFar());
			}
		}
		break;

	case _TauntPole:
		tauntPole.Attack(name);
		break;
	}
}

void CharacterRoadHog::SwitchWeapon(float deltaTime)
{
	switch (weapon)
	{
	case _ScrapGun:
		rScrapGun.ResetReloadTimer();
		weapon = _TauntPole;
		break;

	case _TauntPole:
		weapon = _ScrapGun;
		break;
	}
}


