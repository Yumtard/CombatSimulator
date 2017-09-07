#pragma once

#include "Weapon.h"
#include <string>
#include <iostream>
#include <vector>

class Character
{
public:
	Character(const std::string& name_in, const int health_in);
	virtual void Update(const float deltaTime); 
	virtual void SpecialAttack();
	int GetHealth() const;
	void IsCloseCombat();
	void TakeDamage(const int damage);
	const std::string& GetName() const;
	bool IsDead() const;
	void AddWeapon(Weapon* weapon_in);
	void SwitchWeapon();
	void SetTarget(Character* pTarget_in);
	virtual void Attack();

protected:
	const std::string& name;
	int health;
	bool closeCombat = false; 
	int numWeapons = 0;
	int curWeapon = 0;
	std::vector<Weapon*> weapons;
	Character* pTarget = nullptr;
};