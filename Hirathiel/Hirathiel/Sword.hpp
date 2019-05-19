#pragma once
#include "MeleeWeapon.hpp"

class Sword :public MeleeWeapon {
public:
	Sword(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~Sword(){} 
	virtual void sword() {};
};