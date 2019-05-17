#include "DropList.hpp"

DropList::DropList(SDL_Renderer* renderer, Texture* textures) {
	this->renderer = renderer;
	this->textures = textures;
}
DropList::~DropList() {
	this->renderer = nullptr; this->textures = nullptr;
	delete this->renderer, this->textures;
}

std::vector<Item*> DropList::drop(int mobID, int x, int y) {
	return this->dropCoins(getMaxGold(mobID), x, y);
}

std::vector<Item*> DropList::dropCoins(int maxAmount, int x, int y) {
	std::vector<Item*> drops;
	srand(chrono::system_clock::now().time_since_epoch().count());
	int amount = rand() % maxAmount;
	//std::cout << amount << std::endl;
	int buffer;
	buffer = amount - amount % 50;
	int gold = buffer / 50;
	amount -= buffer;
	buffer = amount - amount % 10;
	int silver = buffer / 10;
	amount -= buffer;
	int bronze = amount;
	//std::cout << "gold:" << gold << std::endl << "silver:" << silver << std::endl << "bronze:" << bronze << std::endl;

	for (int i = 0; i < bronze; i++) {
		drops.push_back(new BronzeCoin(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getBronzeCoin()));
	}
	for (int i = 0; i < silver; i++) {
		drops.push_back(new SilverCoin(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getSilverCoin()));
	}
	for (int i = 0; i < gold; i++) {
		drops.push_back(new GoldCoin(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getGoldCoin()));
	}
	return drops;
}

int DropList::getMaxGold(int mobID) {
	if (mobID == 1) {
		return 55;
	}
	return 86;
}