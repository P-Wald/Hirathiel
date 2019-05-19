#include "Item.hpp"

Item::Item(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :Object((x), (y), 20,20, (renderer), (texture)) {
	this->icon = nullptr;
	this->weight = 1;
}

Item::~Item() {
	this->icon = nullptr; this->renderer = nullptr;
	delete this->icon,this->renderer;
}
