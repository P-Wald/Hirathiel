#pragma once
#include "Item.hpp"

class Coin :public Item {
public:
	Coin(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~Coin();
	int getValue() { return this->value; };
protected:
	int value;
};