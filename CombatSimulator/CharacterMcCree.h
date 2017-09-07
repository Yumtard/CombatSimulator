#pragma once

#include "Character.h"
#include "Gun.h"

class CharacterMcCree :
	public Character
{
public:
	CharacterMcCree(const std::string& name_in, const int health_in);
	virtual void SpecialAttack() override;

private:
};