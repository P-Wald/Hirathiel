#pragma once

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texturebase.hpp"
#include "Timer.hpp"
#include <atomic>

using namespace std;
class Object {
public:
	Object(int x, int y, int w, int h, SDL_Renderer *renderer);
	Object(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture);
	~Object();
	void draw();
	virtual SDL_Rect* getRect() { return this->rect; };

protected:
	void update();
	void initrect();
	virtual bool init();
	virtual void lifebar() {};
protected:
	float angle = 0;
	std::atomic<double> x, y;
	int w, h;
	SDL_Rect *rect;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
};