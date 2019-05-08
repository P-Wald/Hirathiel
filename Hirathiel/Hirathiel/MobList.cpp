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



bool MobList::hit(SDL_Rect* hitBox, int dmg) {
	MobListObject* current = dynamic_cast<MobListObject*>(this->first);
	if (current == nullptr){
		return false;
	}
	//for (int i = 0; i < this->length; i++)
	while (current != nullptr){
		MoB* obj = dynamic_cast<MoB*>(current);
		if (obj) {
			if (obj->isHit(hitBox)) {
				if (current == this->first) {
					this->first = current->getNext();
				}
				current->remove();
				obj->~MoB();
				current->~MobListObject();
				this->length--;
				return true;
			}
		}
		current = dynamic_cast<MobListObject*>(current->getNext());
		obj = nullptr;
		delete obj;
	}
	current = nullptr;
	delete current;
	
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