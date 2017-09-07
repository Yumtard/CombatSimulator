#include "TauntPole.h"

TauntPole::TauntPole(float cooldown, const std::string& ownerName_in)
	:
	Weapon(cooldown, ownerName_in),
	rng(rd())
{
	std::ifstream in("insults.txt");
	std::string str;

	if (in.is_open())
	{
		while (std::getline(in, str))
		{
			insults.push_back(str);
		}
		in.close();
	}
}

bool TauntPole::Attack(const std::string& targetName, const std::string& heroName)
{
	if (cooldownTimer.limitReached())
	{
		std::cout << heroName << " used his " << name << " and it displayed this message to " << targetName << ":" << std::endl;

		std::uniform_int_distribution<int> dist(0, (insults.size() - 1));

		const int msg = dist(rng);

		std::cout << insults[msg] << "\n\n";
	
		return true;
	}

	return false;
}
