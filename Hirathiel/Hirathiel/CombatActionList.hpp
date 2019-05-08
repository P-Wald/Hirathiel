#pragma once
#include "GenericList.hpp"
#include "CombatAction.hpp"
#include "MobList.hpp"

class CombatActionList : public GenericList {
public:
	CombatActionList();
	~CombatActionList();

	void add(CombatAction* add);
	void clear();
	
protected:
};