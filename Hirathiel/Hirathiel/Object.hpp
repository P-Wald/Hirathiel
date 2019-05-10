#pragma once

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texturebase.hpp"
#include "Timer.hpp"
#include <mutex>

using namespace std;
class Object {
public:
	Object(int x, int y, int w, int h, SDL_Renderer *renderer);
	Object(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture);
	~Object();
	void draw();
	virtual SDL_Rect* getRect() { return this->rect; };
	double getX() { poslock.lock(); int x = this->x; poslock.unlock(); return x; };
	double getY() { poslock.lock(); int y = this->y; poslock.unlock(); return y; };


protected:
	void update();
	void initrect();
	virtual bool init();
	virtual void lifebar() {};
protected:
	std::mutex poslock;
	float angle = 0;
	double x, y;
	int w, h;
	SDL_Rect *rect;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
};