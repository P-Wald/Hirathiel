#pragma once
#include "Item.hpp"
#include "Texturebase.hpp"
#include <chrono>
#include <stdlib.h>
#include <vector>
#include "BronzeCoin.hpp"
#include "SilverCoin.hpp"
#include "GoldCoin.hpp"
#include "IronSword.hpp"

class DropList {
public:
	DropList(SDL_Renderer* renderer, Texture* textures);
	~DropList();
	std::vector<Item*> drop(int mobID, int x, int y,int mobLvl);
private:
	std::vector<Item*> dropCoins(int maxAmount,int x, int y,int mobLvl);
	int getMaxGold(int mobID,int mobLvl);
private:
	SDL_Renderer* renderer;
	Texture* textures;
};
