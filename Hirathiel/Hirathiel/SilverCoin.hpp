#pragma once
#include "Coin.hpp"

class SilverCoin :public Coin {
public:
	SilverCoin(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~SilverCoin() {};
private:
};