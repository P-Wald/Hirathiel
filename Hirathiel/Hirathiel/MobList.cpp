#include "MobList.hpp"

MobList::MobList():GenericList(){
	this->first = new MobListObject();
	this->length = 1;
}

MobList::~MobList() {}


void MobList::add(MobListObject* add) {
	if (this->first == nullptr) {
		this->first = add;
	}
	if (dynamic_cast<MoB*>(add)) {
		add->setPrev(this->getLast());
		this->getLast()->setNext(dynamic_cast<GenericListObject*>(add));
		this->length++;
	}
}



bool MobList::hit(CombatAction* action, int dmg) {
	MobListObject* current = dynamic_cast<MobListObject*>(this->first);
	if (current == nullptr || action == nullptr){
		return false;
	}
	//for (int i = 0; i < this->length; i++)
	while (current != nullptr){
		MoB* obj = dynamic_cast<MoB*>(current);
		if (obj) {
			if (obj->isHit(action->getRect())) {
				action->applyEffects(obj);
			}
		}
		current = dynamic_cast<MobListObject*>(current->getNext());
		obj = nullptr;
		delete obj;
	}
	current = nullptr;
	delete current;
	return true;
	
}




void MobList::draw() {
	MobListObject* current = dynamic_cast<MobListObject*>(this->first);

	if (!current)
		return;

	for (int i = 0; i < this->length; i++)
	{

		Object* toDraw = dynamic_cast<Object*>(current);
		if (toDraw) {
			toDraw->draw();
		}
		if (current->getNext() == nullptr)
			break;

		current = dynamic_cast<MobListObject*>(current->getNext());
	}
}

void MobList::triggerEffects() {
	if (!this->first->getNext()) {
		printf("no mob");
		return;
	}
	GenericListObject* current = this->first->getNext();
	while (current) {
		if (dynamic_cast<MoB*>(current)->triggerEffects()) {
			MoB* buffer = dynamic_cast<MoB*>(current);
			buffer->remove();
			delete buffer;
			this->length--;
		}
		current = current->getNext();
	}
	current = nullptr;
	delete current;
}