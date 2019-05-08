#include "CombatActionList.hpp"

CombatActionList::CombatActionList(){
	this->first = nullptr;

}

CombatActionList::~CombatActionList(){

}

void CombatActionList::add(CombatAction* add){
	if (!this->first) {
		printf("first");
		this->first = add;
	}else {
		printf("last");
		this->getLast()->setNext(add);
		add->setPrev(this->getLast());
		printf("post last");
	}
	add = nullptr;
	delete add;
}

void CombatActionList::clear() {
	CombatAction* current = dynamic_cast<CombatAction*>(this->first);
	CombatAction* buffer;
	while (current) {
		if (current->time == 0) {
			buffer = current;
			current = dynamic_cast<CombatAction*>(current->getNext());
			buffer->remove();
		}
		else {
			current = dynamic_cast<CombatAction*>(current->getNext());
		}

	}
	delete current;
}