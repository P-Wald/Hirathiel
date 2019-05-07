#include "MobList.hpp"

MobList::MobList() {
	this->length = 0;
	this->first = new MobListObject();
}

MobList::~MobList() {}

MobListObject* MobList::getLast() {
	MobListObject* current = this->first;
	if (this->first == nullptr) {
		return nullptr;
	}

	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}
	return current;
}

void MobList::add(MobListObject* add) {
	if (dynamic_cast<MoB*>(add)) {
		this->getLast()->setNext(add);
		this->length++;
	}
}

bool MobList::hit(SDL_Rect* hitBox, int dmg) {
	MobListObject* current = this->first;
	if (current == nullptr){
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		MoB* obj = dynamic_cast<MoB*>(current);
		if (obj) {
			if (obj->isHit(hitBox)) {
				current->remove();
				this->length--;
			}
		}
		if (current->getNext() == nullptr) {
			break;
		}
		current = current->getNext();
	}
}

void MobList::draw() {
	MobListObject* current = this->first;

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

		current = current->getNext();
	}
}