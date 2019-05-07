#pragma once

class MobListObject{
public:
	MobListObject();
	MobListObject(long id, MobListObject* next, MobListObject* prev);
	~MobListObject();
	MobListObject* getNext() { return next; };
	bool setNext(MobListObject* next);
	bool isLast() { if (next) { return true; } return false; };
	bool insert(MobListObject* next);
	virtual void remove();
	void setPrev(MobListObject* prev);
	long getID() { return id; };
protected:
	MobListObject* prev;
	MobListObject* next;
	long id;
	
};