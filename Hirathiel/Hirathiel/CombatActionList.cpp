#include "CombatActionList.hpp"

CombatActionList::CombatActionList(){
	this->first = nullptr;

}

CombatActionList::~CombatActionList(){

}

void CombatActionList::add(CombatAction* add){
	if (!this->first) {
		this->first = add;
	}else {
		this->getLast()->setNext(add);
		add->setPrev(this->getLast());
	}
	this->length++;
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
			if (buffer == this->first) {
				this->first = buffer->getNext();
			}
			else {
				buffer->remove();
			}
			buffer->setNext(nullptr);
			buffer->setPrev(nullptr);
			buffer->~CombatAction();
			this->length--;
		}
		else {
			current = dynamic_cast<CombatAction*>(current->getNext());
		}

	}
	delete current;
}

void CombatActionList::draw() {
	CombatAction* current = dynamic_cast<CombatAction*>(this->first);
	while (current) {
		current->draw();
		current = dynamic_cast<CombatAction*>(current->getNext());
	}
}