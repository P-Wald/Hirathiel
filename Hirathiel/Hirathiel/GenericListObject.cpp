#include "GenericListObject.hpp"
#include <stdexcept>

GenericListObject::GenericListObject(GenericListObject* next, GenericListObject* prev){
	this->next = next;
	this->prev = prev;

}
GenericListObject::GenericListObject() {
	this->next = nullptr;
	this->prev = nullptr;
}

GenericListObject::~GenericListObject(){
	delete prev;
}

void GenericListObject::setNext(GenericListObject* next){
	this->next = next;
}

void GenericListObject::setPrev(GenericListObject* prev) {
	this->prev = prev;
}