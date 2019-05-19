#include "DropList.hpp"

DropList::DropList(SDL_Renderer* renderer, Texture* textures) {
	this->renderer = renderer;
	this->textures = textures;
}
DropList::~DropList() {
	this->renderer = nullptr; this->textures = nullptr;
	delete this->renderer, this->textures;
}

std::vector<Item*> DropList::drop(int mobID, int x, int y,int mobLvl) {
	return this->dropCoins(getMaxGold(mobID,mobLvl), x, y,mobLvl);
}

std::vector<Item*> DropList::dropCoins(int maxAmount, int x, int y,int mobLvl) {
	std::vector<Item*> drops;
	srand(chrono::system_clock::now().time_since_epoch().count());
	int amount = rand() % maxAmount;
	std::cout << amount << std::endl;
	int buffer;
	buffer = amount - amount % 10000;
	int gold = buffer / 10000;
	amount -= buffer;
	buffer = amount - amount % 100;
	int silver = buffer / 100;
	amount -= buffer;
	int bronze = amount;
	std::cout << "gold:" << gold << std::endl << "silver:" << silver << std::endl << "bronze:" << bronze << std::endl;

	for (int i = 0; i < bronze; i++) {
		drops.push_back(new BronzeCoin(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getBronzeCoin()));
	}
	for (int i = 0; i < silver; i++) {
		drops.push_back(new SilverCoin(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getSilverCoin()));
	}
	for (int i = 0; i < gold; i++) {
		drops.push_back(new GoldCoin(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getGoldCoin()));
	}

	drops.push_back(new IronSword(x + rand() % 70, y + rand() % 70, this->renderer, this->textures->getIronSword(),mobLvl,7));
	return drops;
}

int DropList::getMaxGold(int mobID,int mobLvl) {
	if (mobID == 0) {
		return 3000;
	}
	if (mobID == 1) {
		return 30*mobLvl;
	}
	return 80;
}