#pragma once
#include "MoB.hpp"
#include "Vector2D.hpp"

class Player :public MoB {
public: 
	Player(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Texture* texture);
	~Player();
	void pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer);


protected:
};