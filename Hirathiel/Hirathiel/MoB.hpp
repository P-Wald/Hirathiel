#pragma once

#include"Object.hpp"
#include"Vector2D.hpp"
#include<SDL.h>

class MoB : public Object {
public:
	MoB(int x, int y, int w, int h, SDL_Renderer *renderer);
	MoB(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture);
	~MoB();
	void move(Vector2D* moveVector);
	void pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer);

private:
	double speed = 400;
};