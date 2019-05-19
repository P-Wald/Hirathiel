#pragma once
#include "Sword.hpp"

class IronSword :public Sword {
public:
	IronSword(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture,int level,int rarity);
	~IronSword() {};
	void apply(MoB* applicant)override;
	void unapply(MoB* applicant)override;
};