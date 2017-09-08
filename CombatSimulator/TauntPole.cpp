#include "TauntPole.h"
#include <string>

TauntPole::TauntPole(WeaponData* data_in)
	:
	Weapon(data_in),
	rng(rd())
{
	std::ifstream in("insults.txt");
	std::string str;

	if (in.is_open())
	{
		while (std::getline(in, str))
		{
			mInsults.push_back(str);
		}
		in.close();
	}
}

bool TauntPole::Attack(const char* targetName_in, const char* ownerName_in)
{
	if (mCooldownTimer.limitReached())
	{
		std::cout << ownerName_in << " used his " << mData->name << " and it displayed this message to " << targetName_in << ":" << std::endl;

		std::uniform_int_distribution<int> dist(0, (int(mInsults.size()) - 1));

		const int msg = dist(rng);

		std::cout << mInsults[msg] << "\n\n";
	
		return true;
	}

	return false;
}
