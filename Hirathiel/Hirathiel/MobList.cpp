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
void MobList::triggerEffects() {
	auto list = this->mobs.get();
	for (int i = 0; i < list.size(); i++) {
		if (this->mobs.getObj(i)->triggerEffects()) {
			this->items->drop(1, list.at(i)->getX(), list.at(i)->getY(),list.at(i)->getLvl());
			this->mobs.remove(i);
			this->score++;
			i--;
			break;
		}
	}
}

void MobList::poll() {
	this->triggerEffects();
	this->draw();
}