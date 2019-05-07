#include "MobListObject.hpp"

MobListObject::MobListObject()
{
	this->id = 1;
	this->next = nullptr;
	this->prev = nullptr;
}

MobListObject::MobListObject(long id, MobListObject* next, MobListObject* prev) {
	this->id = id;
	this->next = next;
	this->prev = prev;
}

MobListObject::~MobListObject(){
	delete prev;
	delete next;
}

bool MobListObject::setNext(MobListObject* next){
	if (this->next == nullptr){
		this->next = next;
		return true;
	}
	return false;
}

void MobListObject::setPrev(MobListObject* prev) {
	this->prev = prev;
}

bool MobListObject::insert(MobListObject* next) {

	if (this->next == nullptr || next == nullptr){
		return false;
	}
	next->setNext(this->next);
	next->setPrev(this);

	this->next->setPrev(next);
	this->next = next;

	return true;
}

void MobListObject::remove(){
	if (prev != nullptr){
		prev->setNext(this->next);
	}
	if (next != nullptr){
		next->setPrev(this->prev);
	}
}