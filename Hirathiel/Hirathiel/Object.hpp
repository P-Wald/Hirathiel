#pragma once

#include <string>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Texturebase.hpp"
#include "Timer.hpp"

using namespace std;
class Object {
public:
	Object(int x, int y, int w, int h, SDL_Renderer *renderer);
	Object(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture);
	~Object();
	void draw();
	void pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer);
	void addNext(Object* next) { this->next = next; };
	Object* getNext() { return this->next; };

protected:
	void update();
	void initrect();
	bool init();
protected:
	double speed = 400;
	float angle = 0;
	double x, y;
	int w, h;
	SDL_Rect *rect;
	SDL_Renderer *renderer;
	SDL_Texture *texture;
	Object* next;
};