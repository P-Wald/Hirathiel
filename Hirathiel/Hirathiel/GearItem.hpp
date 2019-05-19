#pragma once
#include "Item.hpp"
#include "MoB.hpp"

class GearItem :public Item {
public:
	GearItem(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~GearItem() {};
	virtual void equip(MoB* applicant) {};
	virtual void unequip(MoB* applicant) {};
	int getType() { return this->type; };
	int getLevel() { return this->level; };
	int getRarity() { return this->rarity; };

protected:
	int type = 0;
	int level;
	int rarity;
};
