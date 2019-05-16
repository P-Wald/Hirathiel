#include "Item.hpp"

Item::Item(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture,int id) :Object((x), (y), 30,30, (renderer), (texture)) {
	this->icon = nullptr;
	this->id = id;
}

Item::~Item() {
	this->icon = nullptr;
	delete this->icon;
}
