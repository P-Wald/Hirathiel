//#include "GenericList.hpp"
//#include <iostream>
//
//GenericList::GenericList() {
//	this->length = 0;
//	this->first = nullptr;
//}
//
//GenericList::~GenericList() {
//	delete first;
//}
//
//GenericListObject* GenericList::getLast() {
//	GenericListObject* current = dynamic_cast<GenericListObject*>(this->first);
//	if (!current) {
//		if (!this->first) { printf("test"); }
//		return nullptr;
//	}
//
//	while (current->getNext() != nullptr){
//		current = current->getNext();
//	}
//	return current;
//}
//
//void GenericList::add(GenericListObject* add){
//	if (this->first == nullptr) {
//		this->first = add;
//	}
//	add->setPrev(this->getLast());
//	this->getLast()->setNext(add);
//	this->length++;
//}