#include "GenericList.hpp"

GenericList::GenericList() {
	this->length = 0;
	this->first = nullptr;
}

GenericList::~GenericList() {
	delete first;
}

GenericListObject* GenericList::getLast() {
	GenericListObject* current = dynamic_cast<GenericListObject*>(this->first);
	if (this->first == nullptr) {
		return nullptr;
	}

	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}
	return current;
}

void GenericList::add(GenericListObject* add){
	if (this->first == nullptr) {
		this->first = add;
	}
	add->setPrev(this->getLast());
	this->getLast()->setNext(add);
	this->length++;
}