#pragma once
#include "Coin.hpp"

class BronzeCoin :public Coin {
public:
	BronzeCoin(int x, int y, SDL_Renderer* renderer,SDL_Texture* texture);
	~BronzeCoin() {};

protected:
};