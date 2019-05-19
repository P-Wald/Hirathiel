#pragma once

#include "Object.hpp"
#include "Vector2D.hpp"
#include  <SDL.h>
#include "MobListObject.hpp"
#include "Resolution.hpp"
#include "Stack.hpp"
#include "Effect.hpp"
#include "CombatStats.hpp"


class MoB : public Object{
public:
	MoB(int x, int y, int w, int h, SDL_Renderer *renderer);
	MoB(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture);
	~MoB();
	bool applyDmg(int dmg);
	bool init();
	void virtual move(Vector2D* moveVector);
	double getLife() { return this->life; };
	bool isHit(SDL_Rect* rect);
	SDL_Rect* getRect() { return this->rect; };
	void setRes(Resolution* res);
	virtual bool triggerEffects();
	void addEffect(Effect* effect);
	double getSpeed() { return this->speed; };
	void setSpeed(int speed) { this->speed = speed; };
	void setLife(int life, int lifeMAX);
	int getFaction() { return this->faction; };
	int getLifeMax() { return this->lifeMAX; };
	int getLvl() { return this->level; };
	void setLvl(int lvl) { this->level = lvl; };
	Combatstats* stats;

protected:
	int level = 1;
	int type = 1;
	void updateLifeBar();
	void lifebar() override;
	void boundaries();
	double speed = 200;
	double life = 150;
	double lifeMAX = 150;
	float lifebarRate;
	int lifeBarFillPerc;
	Resolution* res;
	Stack<Effect> effects;
	SDL_Rect* lifebarlow;
	SDL_Rect* lifebarup;
	int faction = 1;
};
