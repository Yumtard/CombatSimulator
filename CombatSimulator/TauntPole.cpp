#include "TauntPole.h"

TauntPole::TauntPole(float cooldown, const std::string& ownerName_in)
	:
	Weapon(cooldown, ownerName_in),
	rng(rd())
{}

bool TauntPole::Attack(const std::string& targetName, const std::string & heroName)
{
	if (cooldownTimer.limitReached())
	{
		std::cout << heroName << " used his " << name << " and it displayed this message to " << targetName << ":" << std::endl;
		std::uniform_int_distribution<int> dist(1, 10);
		const int msg = dist(rng);

		switch (msg)
		{
		case 1:
			std::cout << "\"Life isn't easy, but your mom is.\"\n\n";
			break;
		case 2:
			std::cout << "\"I would insult your mother, but cows are sacred in my country.\"\n\n";
			break;
		case 3:
			std::cout << "\"I bet your mother has a loud bark.\"\n\n";
			break;
		case 4:
			std::cout << "\"Your family tree must be a cactus because you're all pricks.\"\n\n";
			break;
		case 5:
			std::cout << "\"How were you born? Your dad has no balls!\"\n\n";
			break;
		case 6:
			std::cout << "\"You're so poor, when you asked your Mom whats for dinner she opened her legs and said crabs.\"\n\n";
			break;
		case 7:
			std::cout << "\"You mother is so old she went to an antiques auction and people bid on her.\"\n\n";
			break;
		case 8:
			std::cout << "\"Ever since I saw you in your family tree, I've wanted to cut it down.\"\n\n";
			break;
		case 9:
			std::cout << "\"Are your parents siblings?\"\n\n";
			break;
		case 10:
			std::cout << "\"Did you know they used to be called \"Jumpolines\" until your mom jumped on one?\"\n\n";
			break;
		}

		return true;
	}

	return false;
}
