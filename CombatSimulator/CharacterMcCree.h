#pragma once

#include "Character.h"
#include "Gun.h"

class CharacterMcCree :
	public Character
{
public:
	CharacterMcCree(const std::string name_in, const int health_in, Gun& rRevolver_in);
	virtual void Update(const float deltaTime);
	virtual void Attack();

private:
	Gun& rRevolver;
};