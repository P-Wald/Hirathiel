#pragma once

 class GenericListObject {
 public:
	 GenericListObject();
	 GenericListObject(GenericListObject* next, GenericListObject* prev);
	 ~GenericListObject();
	 GenericListObject* getNext() { return this->next; };
	 GenericListObject* getPrev() { return this->prev; };
	 void setNext(GenericListObject* next);
	 void setPrev(GenericListObject* prev);
	 virtual long getID() { return 0; };

 protected:
	 GenericListObject* prev;
	 GenericListObject* next;

};
