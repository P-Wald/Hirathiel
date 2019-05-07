#pragma once
#include "GenericListObject.hpp"

class MobListObject: public GenericListObject{
public:
	MobListObject();
	MobListObject(long id,GenericListObject* next, GenericListObject* prev);
	~MobListObject();
	bool isLast() { if (next) { return true; } return false; };
	bool insert(MobListObject* next);
	virtual void remove();
	long getID() { return id; };
protected:
	long id;
};