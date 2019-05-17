#include "GoldCoin.hpp"

GoldCoin::GoldCoin(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :Coin((x), (y), (renderer), (texture)) {
	this->value = 50;
}