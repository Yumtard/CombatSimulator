#include "Character.h"

Character::Character(const std::string& name_in, const int health_in)
	:
	name(name_in),
	health(health_in)
{}

void Character::SetOpponent(Character * pOpponent_in)
{
	pOpponent = pOpponent_in;
}

void Character::Update(const float deltaTime)
{
	Attack();
}

void Character::Attack()
{
	std::cout << name << " attacked!\n";
}

void Character::SpecialAttack()
{
	std::cout << name << " used his special Attack!\n";
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

