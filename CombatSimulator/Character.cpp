#include "Character.h"

Character::Character(const std::string& name_in, const int health_in)
	:
	name(name_in),
	health(health_in)
{}

void Character::Update(const float deltaTime)
{
	if (!IsDead())
	{
		weapons[curWeapon]->Update(deltaTime);
		Attack();
	}
}

int Character::GetHealth() const
{
	return health;
}

void Character::IsCloseCombat()
{
	closeCombat = true;
}

void Character::TakeDamage(const int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
	}
	std::cout << name << " took " <<  damage <<" damage\n"
		<< name << " has " << health << " HP left.\n\n";
}

const std::string& Character::GetName() const
{
	return name;
}

bool Character::IsDead() const
{
	return health <= 0;
}

void Character::AddWeapon(Weapon * weapon_in)
{
	numWeapons++;
	weapons.push_back(weapon_in);
}

void Character::SwitchWeapon()
{
	weapons[curWeapon]->Reset();

	if ((curWeapon + 1) == numWeapons)
	{
		curWeapon = 0;
	}
	else
	{
		curWeapon++;
	}
}

void Character::SetTarget(Character * pTarget_in)
{
	pTarget = pTarget_in;
}

void Character::Attack()
{
	const std::string targetName = pTarget->GetName();

	if (closeCombat)
	{
		const int dmgNear = weapons[curWeapon]->GetDamageNear();
		if (weapons[curWeapon]->Attack(targetName, name) && dmgNear > 0)
		{
			pTarget->TakeDamage(dmgNear);
		}
	}
	else
	{
		const int dmgFar = weapons[curWeapon]->GetDamageFar();
		if (weapons[curWeapon]->Attack(targetName, name) && dmgFar > 0)
		{
			pTarget->TakeDamage(dmgFar);
		}
	}
}

