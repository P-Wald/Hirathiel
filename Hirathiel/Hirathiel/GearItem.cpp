#include "GearItem.hpp"

GearItem::GearItem(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :Item((x), (y), (renderer), (texture)) {
	this->rect->w = 45;
	this->rect->h = 45;
}
