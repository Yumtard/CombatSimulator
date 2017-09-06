#pragma once

#include <string>
#include <iostream>

class Character
{
public:
	Character(const std::string& name_in, const int health_in);
	void SetOpponent(Character* pOpponent_in); 
	virtual void Update(const float deltaTime); 
	virtual void Attack();
	virtual void SpecialAttack();
	int GetHealth() const;
	void IsCloseCombat();
	void TakeDamage(const int damage);
	const std::string& GetName() const;
	bool IsDead() const;

protected:
	const std::string& name;
	int health;
	bool closeCombat = false; 
	Character* pOpponent = nullptr; 
};