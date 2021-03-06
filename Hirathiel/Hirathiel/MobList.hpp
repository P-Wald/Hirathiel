#pragma once
#include "MobListObject.hpp"
#include "MoB.hpp"
#include <SDL.h>
#include "Object.hpp"
#include "GenericList.hpp"
#include "CombatAction.hpp"
#include <mutex>
#include "Stack.hpp"
#include "ItemList.hpp"


class MobList{
public:
	MobList(ItemList* items);
	~MobList();
	void add(MoB* add);
	void draw();
	void triggerEffects(std::mutex* moblock);
	int getScore() { return this->score; };
	int getSize() { return this->mobs.get().size(); }
	std::vector<MoB*> get() { return this->mobs.get(); };


private:
	Stack<MoB> mobs;
	ItemList* items;
	int score;
};
