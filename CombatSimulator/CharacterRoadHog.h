#pragma once

#include "Character.h"
#include "Timer.h"
#include "Gun.h"
#include "TauntPole.h"
#include <string>

class CharacterRoadHog :
	public Character
{
public:
	CharacterRoadHog(const std::string& name_in, const int health_in, Gun& rScrapGun_in, TauntPole& rTauntPole_in, 
		float specialAttackTimeLimit, float weaponSwitchTimeLimit);
	enum WeaponType
	{
		_ScrapGun, _TauntPole
	};
	virtual void Update(const float deltaTime);
	virtual void SpecialAttack();
	virtual void Attack();
	void SwitchWeapon(float deltaTime);

private:
	Timer specialAttackTimer;
	Timer weaponSwitchTimer;
	Gun& rScrapGun;
	TauntPole& tauntPole;
	WeaponType weapon = _ScrapGun;
};