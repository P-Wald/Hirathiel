#include "ItemList.hpp"

ItemList::ItemList(SDL_Renderer* renderer,Texture* textures) {
	this->renderer = renderer;
	this->textures = textures;
	this->droplist= new DropList(this->renderer, this->textures);
}

ItemList::~ItemList() {
	this->renderer = nullptr; this->textures = nullptr; this->droplist = nullptr;
	delete this->renderer, this->textures, this->droplist;
}

void ItemList::drop(int mobid,int x,int y) {
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	if (rand() % 100 < 60) {
		auto drops = droplist->drop(mobid, x, y);
		for (int i = 0; i < drops.size(); i++) {
			this->items.add(drops.at(i));
		}
	}
}

std::vector<Item*> ItemList::pickup(int x, int y) {
	auto list = this->items.get();
	std::vector<Item*> result;
	for (int i = 0; i < list.size(); i++) {
		int distanceX, distanceY;
		distanceX = list.at(i)->getX() - x;
		distanceY = list.at(i)->getY() - y;
		if (distanceX < 0) { distanceX *= -1; }
		if (distanceY < 0) { distanceY *= -1; }
		if (distanceX <= 50 && distanceY <= 50) {
			Item* drop = this->items.getObj(i);
			this->items.remove(i);
			result.push_back(drop);
		}
	}

	return result;
}

void ItemList::draw() {
	auto list = this->items.get();
	for (int i = 0; i < list.size(); i++) {
		list.at(i)->draw();
	}
}