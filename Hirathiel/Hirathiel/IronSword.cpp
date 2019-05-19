#include "IronSword.hpp"
#include <chrono>

IronSword::IronSword(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture, int level, int rarity):Sword((x),(y),(renderer),(texture)){
	srand(chrono::system_clock::now().time_since_epoch().count());
	int attackmultiplicator = rand()%(level*rarity);
	this->attackBonus = (level * rarity) * attackmultiplicator;
	int critchancemultiplicator = (rand() % (level * rarity))/10;
	this->critchance = critchancemultiplicator;
	int critmulti = rand();
	this->crit = 1 + critmulti / 10;
	this->level = level;
	this->rarity = rarity;

}

void IronSword::apply(MoB* applicant) {
}

void IronSword::unapply(MoB* applicant) {
}
