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
	MoB* current = dynamic_cast<MoB*>(mobs->getFirst()->getNext());
	auto list = this->list.get();
	while (current) {
		for (int i = 0; i < list.size(); i++) {
			if (current->isHit(list.at(i)->getRect())&&current->getFaction()!=list.at(i)->getFaction()) {
				CombatAction* obj = this->list.getObj(i);
				obj->applyEffects(current);
				obj = nullptr; delete obj;
			}
		}
		current = dynamic_cast<MoB*>(current->getNext());
	}

}



void drawItem(CombatAction* action) {
	action->draw();
}

void CombatActionList::draw() {
	this->list.forEach(drawItem);
}
