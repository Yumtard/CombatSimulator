#pragma once

#include "Character.h"
#include "CharacterData.h"
#include "Gun.h"

class CharacterMcCree :
	public Character
{
public:
	CharacterMcCree(CharacterData* data_in);
	virtual void SpecialAttack() override;

private:
};