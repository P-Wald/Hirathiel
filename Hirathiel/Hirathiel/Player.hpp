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
	inline int getCoins() { return this->bronze + this->silver * 10 + this->gold * 100; };
	inline int getBronze() { return this->bronze; };
	inline int getSilver() { return this->silver; };
	inline int getGold() { return this->gold; };
	void updatePurse();

	void chargeCoins(int gold,int silver,int bronze);
	std::string getMoney();

protected:
	ItemList* items;
	ItemList* playerItems;
	double life;
	double lifeMAX;
	int gold;
	int silver;
	int bronze;
};