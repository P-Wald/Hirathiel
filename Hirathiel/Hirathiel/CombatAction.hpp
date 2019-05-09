#pragma once
#include "Vector2D.hpp"
#include <SDL.h>
#include "Effect.hpp"
#include <stdlib.h>
#include <chrono>
#include "Timer.hpp"

class CombatAction :public GenericListObject{
public:

	CombatAction();
	CombatAction(int x, int y,SDL_Rect* rect, SDL_Texture* texture,SDL_Renderer* renderer);
	~CombatAction();
	inline int getX() { return x; };
	inline int getY() { return y; };
	void draw();
	inline SDL_Rect* getRect() { return rect; };
	virtual void applyEffects(MoB* applicant) {};
	virtual void addEffects() {};
	void remove();

protected:
	int x,y,w,h;
	SDL_Rect* rect;
	SDL_Texture* texture;
	SDL_Renderer* renderer;
	float angle = 0;
	Effect* effects;
	int critchance=0;
	float crit=1;
};