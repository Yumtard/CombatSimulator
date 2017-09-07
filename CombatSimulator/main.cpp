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
	Gun revolver(35, 70, 6, 1.5f, 0.5f, mcCreeName);
	Gun scrapGun(20, 255, 4, 1.5f, 1.0f, roadHogName);
	TauntPole tauntPole(1.0f, roadHogName);
	Weapon* pRevolver = &revolver;
	Weapon* pScrapGun = &scrapGun;
	Weapon* pTauntPole = &tauntPole;
	CharacterMcCree mcCree(mcCreeName, 200);
	CharacterRoadHog roadHog(roadHogName, 600, 30.0f, 2.0f);
	const float deltaTime = 0.1f;
	bool running = true;

	mcCree.AddWeapon(pRevolver);
	roadHog.AddWeapon(pScrapGun);
	roadHog.AddWeapon(pTauntPole);

	mcCree.SetTarget(&roadHog);
	roadHog.SetTarget(&mcCree);


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

