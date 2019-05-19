#pragma once
#include "GearItem.hpp"

class Weapon:public GearItem {
public:
	Weapon(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~Weapon() {};
	void equip(MoB* applicant)override;
	void unequip(MoB* applicant)override;
	virtual void apply(MoB* applicant) {};
	virtual void unapply(MoB* applicant) {};

protected:
	int attackBonus = 0;
	int critchance = 0;
	float crit = 0;
};
