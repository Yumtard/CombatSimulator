#pragma once

#include "Character.h"
#include "Timer.h"
#include "Gun.h"
#include "TauntPole.h"

class CharacterRoadHog :
	public Character
{
public:
	CharacterRoadHog(CharacterData* data_in);
	virtual void Update(const float dt_in) override;
	virtual void SpecialAttack() override;

private:
	Timer mSpecialAttackTimer;
	Timer mWeaponSwitchTimer;
};