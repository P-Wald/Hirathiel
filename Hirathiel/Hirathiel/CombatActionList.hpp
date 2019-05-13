#pragma once
#include "GenericList.hpp"
#include "CombatAction.hpp"
#include "MobList.hpp"
#include "Stack.hpp"

class CombatActionList{
public:
	CombatActionList();
	~CombatActionList();

	void add(CombatAction* add);
	void clear();
	void draw();
	void hit(MobList* mobs);
	void setMobs(MobList* mobs) { this->mobs = mobs; };
	void poll();

	
protected:
	MobList* mobs;
	Stack<CombatAction> list;
};