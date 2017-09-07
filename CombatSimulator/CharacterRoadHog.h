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
	CharacterRoadHog(const std::string& name_in, const int health_in,
		float specialAttackTimeLimit, float weaponSwitchTimeLimit);
	virtual void Update(const float deltaTime) override;
	virtual void SpecialAttack() override;

private:
	Timer specialAttackTimer;
	Timer weaponSwitchTimer;
};