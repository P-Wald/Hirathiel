#pragma once
#include "Coin.hpp"

class GoldCoin :public Coin {
public:
	GoldCoin(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~GoldCoin() {};
private:
};