#include "CombatActionList.hpp"
#include "MoB.hpp"

CombatActionList::CombatActionList(){
}

CombatActionList::~CombatActionList(){

}

void CombatActionList::add(CombatAction* add){
	list.add(add);
}


void CombatActionList::poll() {
	this->hit(this->mobs);
	this->clear();
	this->draw();
}




void CombatActionList::clear() {
	auto list = this->list.get();
	for (int i = 0; i<list.size(); i++) {
		this->list.remove(i);
	}
}

void CombatActionList::hit(MobList* mobs) {
	auto list = mobs->get();
	auto attack = this->list.get();
	for (int i = 0; i < list.size(); i++) {
		for (int x = 0; x < attack.size(); x++) {
			if (list.at(i)->isHit(attack.at(x)->getRect()) && list.at(i)->getFaction() == attack.at(x)->getFaction()) {
				attack.at(x)->applyEffects(list.at(i));
			}
		}
	}
}



void drawItem(CombatAction* action) {
	action->draw();
}

void CombatActionList::draw() {
	this->list.forEach(drawItem);
}
