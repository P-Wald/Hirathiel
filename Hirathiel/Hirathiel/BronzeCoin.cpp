#include "BronzeCoin.hpp"

BronzeCoin::BronzeCoin(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :Coin((x), (y), (renderer), (texture)) {
	this->weight = 0.0;
	this->value = 1;
}