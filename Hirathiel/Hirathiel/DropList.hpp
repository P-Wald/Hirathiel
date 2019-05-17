#pragma once
#include "Item.hpp"
#include "Texturebase.hpp"
#include <chrono>
#include <stdlib.h>
#include <vector>
#include "BronzeCoin.hpp"
#include "SilverCoin.hpp"
#include "GoldCoin.hpp"

class DropList {
public:
	DropList(SDL_Renderer* renderer, Texture* textures);
	~DropList();
	std::vector<Item*> drop(int mobID, int x, int y);
private:
	std::vector<Item*> dropCoins(int maxAmount,int x, int y);
	int getMaxGold(int mobID);
private:
	SDL_Renderer* renderer;
	Texture* textures;
};
