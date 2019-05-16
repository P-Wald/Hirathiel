#pragma once
#include "Item.hpp"
#include "Stack.hpp"
#include "Texturebase.hpp"
#include <chrono>
#include <stdlib.h>

class ItemList {
public:
	ItemList(SDL_Renderer* renderer, Texture* textures);
	~ItemList();
	void drop(int mobid, int x, int y);
	Item* pickup(int x, int y);
	void draw();

private:
	Stack<Item> items;
	SDL_Renderer* renderer;
	Texture* textures;

};