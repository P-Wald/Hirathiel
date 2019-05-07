#pragma once

#include"Object.hpp"
#include"Vector2D.hpp"
#include<SDL.h>
#include "MobListObject.hpp"

class MoB : public Object, public MobListObject {
public:
	MoB(int x, int y, int w, int h, SDL_Renderer *renderer);
	MoB(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture);
	~MoB();
	bool init();
	void virtual move(Vector2D* moveVector);
	double getLife() { return this->life; };
	bool isHit(SDL_Rect* rect);
	SDL_Rect* getRect() { return this->rect; };
protected:
	double speed = 0;
	double life = 0;
};