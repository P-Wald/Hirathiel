#pragma once
#include "MobListObject.hpp"
#include "MoB.hpp"
#include <SDL.h>
#include "Object.hpp"
#include "GenericList.hpp"
class MobList: public GenericList{
public:
	MobList();
	~MobList();
	void add(MobListObject* add);
	bool hit(SDL_Rect* hit, int dmg);
	void draw();
};
