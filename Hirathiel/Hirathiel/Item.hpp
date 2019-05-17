#pragma once
#include "Object.hpp"
#include <SDL.h>
#include <chrono>
#include <stdlib.h>


class Item :public Object {
public:
	Item(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture);
	~Item();
	void setIcon(SDL_Texture* icon) { this->icon = icon; };
	float getWeight() { return this->weight; };


protected:
	SDL_Texture* icon;
	float weight;

};