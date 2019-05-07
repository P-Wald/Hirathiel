#include "MobList.hpp"

MobList::MobList():GenericList(){
	this->first = new MobListObject();
}

MobList::~MobList() {}


void MobList::add(MobListObject* add) {
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
	for (int i = 0; i < this->length; i++)
	{
		MoB* obj = dynamic_cast<MoB*>(current);
		if (obj) {
			if (obj->isHit(hitBox)) {
				current->remove();
				MobListObject* test = current;
				this->length--;
				return true;
			}
		}
		if (current->getNext() == nullptr) {
			break;
		}
		current = dynamic_cast<MobListObject*>(current->getNext());
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