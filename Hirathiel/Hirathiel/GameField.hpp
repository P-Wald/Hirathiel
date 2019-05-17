#pragma once
#include <SDL.h>
#include "MobList.hpp"
#include "ItemList.hpp"
#include "Texturebase.hpp"

class GameField {
public:
	GameField(MobList* mobs,ItemList* items);
	~GameField() {};
	void pollField();
	void renderField();
private:
	MobList* mobs;
	ItemList* items;
};
