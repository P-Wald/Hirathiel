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


void MobList::triggerEffects(std::mutex* moblock) {
	if (!this->first->getNext()) {
		return;
	}
	GenericListObject* current = this->first->getNext();
	while (current) {
		if (dynamic_cast<MoB*>(current)->triggerEffects()) {
			MoB* buffer = dynamic_cast<MoB*>(current);
			moblock->lock();
			buffer->remove();
			delete buffer;
			moblock->unlock();
			this->length--;
			break;
		}
		if (current) {
			current = current->getNext();
		}
	}
	current = nullptr;
	delete current;
}