#pragma once

#include "CharacterMcCree.h"
#include "CharacterRoadHog.h"
#include "Gun.h"
#include "TauntPole.h"
#include "WeaponData.h"
#include "WeaponData.h"
#include "Weapon.h"

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
	//Variables simulation
	const float dt = 0.1f;
	bool running = true;

	//roadhog character
	CharacterData roadHogData;
	roadHogData.maxHealth = 600;
	roadHogData.maxNumWeapons = 2;
	roadHogData.name = "Road Hog";
	roadHogData.specialAttackTime = 30.0f;
	roadHogData.weaponSwitchTime = 2.0f;
	CharacterData* pRoadHogData = &roadHogData;
	CharacterRoadHog roadHog(pRoadHogData);

	//mcCree character
	CharacterData mcCreeData;
	mcCreeData.maxHealth = 200;
	mcCreeData.maxNumWeapons = 1;
	mcCreeData.name = "McCree";
	CharacterData* pMcCreeData = &mcCreeData;
	CharacterMcCree mcCree(pMcCreeData);

	//roadhog weapons
	WeaponData tauntPoleData;
	tauntPoleData.cooldownTime = 1.0f;
	tauntPoleData.name = "taunt pole";
	tauntPoleData.ownerName = roadHogData.name;
	WeaponData* pTauntPoleData = &tauntPoleData;
	TauntPole tauntPole(pTauntPoleData);

	WeaponData scrapGunData;
	scrapGunData.cooldownTime = 1.0f;
	scrapGunData.damageFar = 20;
	scrapGunData.damageNear = 225;
	scrapGunData.maxMagazineSize = 4;
	scrapGunData.name = "scrap gun";
	scrapGunData.ownerName = roadHogData.name;
	scrapGunData.reloadTime = 1.5f;
	WeaponData* pScrapGunData = &scrapGunData;
	Gun scrapGun(pScrapGunData);

	//mccree weapons
	WeaponData revolverData;
	revolverData.cooldownTime = 0.5f;
	revolverData.damageFar = 35;
	revolverData.damageNear = 70;
	revolverData.maxMagazineSize = 6;
	revolverData.name = "revolver";
	revolverData.ownerName = mcCreeData.name;
	revolverData.reloadTime = 1.5f;
	WeaponData* pRevolverData = &revolverData;
	Gun revolver(pRevolverData);
	
	//Adding weapons and setting targets
	mcCree.AddWeapon(&revolver);
	roadHog.AddWeapon(&scrapGun);
	roadHog.AddWeapon(&tauntPole);
	mcCree.SetTarget(&roadHog);
	roadHog.SetTarget(&mcCree);

	//Simulation loop
	while (running)
	{
		roadHog.Update(dt);
		mcCree.Update(dt);

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

