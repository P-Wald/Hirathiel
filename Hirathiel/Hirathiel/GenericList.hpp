#pragma once
#include "GenericListObject.hpp"

class GenericList {
public:
	GenericList();
	~GenericList();

	void add(GenericListObject* add);
	GenericListObject* getFirst() { return this->first; };
	GenericListObject* getLast();

protected:
	GenericListObject* first;
	int length;
};