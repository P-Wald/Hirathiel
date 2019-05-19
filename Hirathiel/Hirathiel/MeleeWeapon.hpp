#pragma once
#include "Weapon.hpp"

class MeleeWeapon :public Weapon {
public:
	MeleeWeapon(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~MeleeWeapon() {};
	int getRange() { return this->range; };
	virtual void melee() {};
	

protected:
	int range = 75;
};
