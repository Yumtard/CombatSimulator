#pragma once

#include "CharacterMcCree.h"
#include "CharacterRoadHog.h"
#include "Gun.h"
#include "TauntPole.h"

//Displays a message for when the combat is over
void Summary(Character& winner, Character& loser)
{
	std::cout << "The match is over." << std::endl;
	std::cout << winner.GetName() << " won and has " << winner.GetHealth() << " HP left." << std::endl;
}

void Draw()
{
	std::cout << "The match is over.\nBoth players died." << std::endl;
}

int main()
{
	//Variables
	const std::string roadHogName = "RoadHog";
	const std::string mcCreeName = "McCree";
	Gun revolver(35, 70, 6, 1.5f, 0.5f);
	Gun scrapGun(20, 255, 4, 1.5f, 1.0f);
	TauntPole tauntPole(1.0f);
	CharacterMcCree mcCree(mcCreeName, 200, revolver);
	CharacterRoadHog roadHog(roadHogName, 600, scrapGun, tauntPole, 30.0f, 2.0f);
	const float deltaTime = 0.1f;
	bool running = true;

	mcCree.SetOpponent(&roadHog);
	roadHog.SetOpponent(&mcCree);

	//Simulation loop
	while (running)
	{
		roadHog.Update(deltaTime);
		mcCree.Update(deltaTime);

		//Exit the loop if either character is out of HP
		if (mcCree.IsDead())
		{
			if (roadHog.IsDead())
			{
				Draw();
			}
			else
			{
				Summary(roadHog, mcCree);
			}
			
			running = false;
		}
		else if (roadHog.IsDead())
		{
			Summary(mcCree, roadHog);
			running = false;
		}
	}

	return 0;
}

