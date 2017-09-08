#pragma once

#include "Weapon.h"
#include "CharacterData.h"
#include <iostream>
#include <vector>

class Character
{
public:
	Character(CharacterData* data_in);
	virtual void Update(const float dt_in); 
	virtual void SpecialAttack() = 0;
	int GetHealth() const;
	void IsCloseCombat();
	void TakeDamage(const int damage_in);
	const char* GetName() const;
	bool IsDead() const;
	void AddWeapon(Weapon* weapon_in);
	void SwitchWeapon();
	void SetTarget(Character* pTarget_in);
	virtual void Attack();

protected:
	int mHealth;
	bool mCloseCombat = false; 
	int mNumWeapons = 0;
	int mCurWeapon = 0;
	Character* pTarget = nullptr;
	CharacterData* mData = nullptr;
};