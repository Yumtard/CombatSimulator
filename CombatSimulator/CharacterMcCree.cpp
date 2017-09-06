#include "CharacterMcCree.h"

CharacterMcCree::CharacterMcCree(const std::string& name_in, const int health_in, Gun& rRevolver_in)
	:
	Character(name_in, health_in),
	rRevolver(rRevolver_in)
{}

void CharacterMcCree::Update(const float deltaTime)
{
	if (!IsDead())
	{
		rRevolver.Update(deltaTime, name);
		Attack();
	}
}

void CharacterMcCree::Attack()
{
	if (rRevolver.Shoot(pOpponent->GetName(), name))
	{
		if (closeCombat)
		{
			pOpponent->TakeDamage(rRevolver.GetDamageNear());
		}
		else
		{
			pOpponent->TakeDamage(rRevolver.GetDamageFar());
		}
	}
}
