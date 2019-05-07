#pragma once
#include "MobListObject.hpp"
#include "MoB.hpp"
#include <SDL.h>
#include "Object.hpp"

class MobList {
public:
	MobList();
	~MobList();
	void add(MobListObject* add);
	bool hit(SDL_Rect* hit, int dmg);
	void draw();
	MobListObject* getFirst() { return this->first; };

protected:
	MobListObject* first;
	int length;

protected:
	MobListObject* getLast();
};
