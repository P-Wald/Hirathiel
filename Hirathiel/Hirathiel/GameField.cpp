#include "GameField.hpp"

GameField::GameField(MobList* mobs, ItemList* items) {
	this->mobs = mobs;
	this->items = items;
}

void GameField::pollField() {
	this->mobs->poll();
	this->items->draw();
}

void GameField::renderField() {
	this->items->draw();
	this->mobs->draw();
}