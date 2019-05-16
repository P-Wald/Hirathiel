#include "ItemList.hpp"

ItemList::ItemList(SDL_Renderer* renderer,Texture* textures) {
	this->renderer = renderer;
	this->textures = textures;
}

ItemList::~ItemList() {
}

void ItemList::drop(int mobid,int x,int y) {
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	if (rand() % 100 < 30) {
		int random = rand() % 20;
		for (int i = 0; i < random; i++) {
			this->items.add(new Item(x+rand()%10, y+rand()%10, this->renderer, this->textures->getCoin(), 1));
		}
	}
}

Item* ItemList::pickup(int x, int y) {
	auto list = this->items.get();
	for (int i = 0; i < list.size(); i++) {
		int distanceX, distanceY;
		distanceX = list.at(i)->getX() - x;
		distanceY = list.at(i)->getY() - y;
		if (distanceX < 0) { distanceX *= -1; }
		if (distanceY < 0) { distanceY *= -1; }
		if (distanceX <= 50 && distanceY <= 50) {
			Item* drop = this->items.getObj(i);
			this->items.remove(i);
			return drop;
		}
	}
	return nullptr;
}

void ItemList::draw() {
	auto list = this->items.get();
	for (int i = 0; i < list.size(); i++) {
		list.at(i)->draw();
	}
}