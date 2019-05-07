#include "GenericList.hpp"

GenericList::GenericList() {
	this->length = 0;
	this->first = new GenericListObject();
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
	this->getLast()->setNext(add);
	this->length++;
}