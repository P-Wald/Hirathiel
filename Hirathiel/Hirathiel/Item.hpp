#pragma once
#include "Object.hpp"
#include <SDL.h>
#include <chrono>
#include <stdlib.h>


class Item :public Object {
public:
	Item(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture,int id);
	~Item();
	void setID(int ID) { this->id = id; };
	int getID() { return this->id; };
	void setIcon(SDL_Texture* icon) { this->icon = icon; };

protected:
	SDL_Texture* icon;
	int id;

};