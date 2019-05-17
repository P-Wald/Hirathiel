#include "MobList.hpp"

MobList::MobList(ItemList* items){
	this->items = items;
	this->score = 0;
}

MobList::~MobList() {}


void MobList::add(MoB* add) {
	this->mobs.add(add);
}


void MobList::draw() {
	auto list = this->mobs.get();
	for (int i = 0; i < list.size(); i++) {
		list.at(i)->draw();
	}

}



//Needs fix: can only remove one MoB at a time
void MobList::triggerEffects(std::mutex* moblock) {
	auto list = this->mobs.get();
	for (int i = 0; i < list.size(); i++) {
		if (this->mobs.getObj(i)->triggerEffects()) {
			this->items->drop(1, list.at(i)->getX(), list.at(i)->getY());
			this->mobs.remove(i);
			this->score++;
			i--;
			break;
		}
	}
}

void MobList::poll(std::mutex*  lock) {
	this->triggerEffects(lock);
	this->draw();
}