#pragma once
#include "MoB.hpp"
#include "Vector2D.hpp"
#include "Strike.hpp"
#include "HiddenDagger.hpp"
#include "ItemList.hpp"

class Player :public MoB {
public: 
	Player(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Texture* texture,ItemList* items);
	~Player();
	CombatAction* pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer);
	bool triggerEffects() override;

protected:
	ItemList* items;
	double life;
	double lifeMAX;
};