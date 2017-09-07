#include "CharacterMcCree.h"

CharacterMcCree::CharacterMcCree(const std::string& name_in, const int health_in)
	:
	Character(name_in, health_in)
{}

void CharacterMcCree::SpecialAttack()
{
	//put special attack here
	std::cout << "McCree has no special attack yet\n";
}

