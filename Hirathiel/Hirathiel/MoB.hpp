#pragma once

#include"Object.hpp"
#include"Vector2D.hpp"
#include<SDL.h>
#include "MobListObject.hpp"
#include "Resolution.hpp"



class MoB : public Object, public MobListObject {
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
	bool triggerEffects();
	void addEffect(GenericListObject* effect);
	double getSpeed() { return this->speed; };
	void setSpeed(int speed) { this->speed = speed; };

protected:
	
	void updateLifeBar();
	void lifebar() override;
	void boundaries();
	double speed = 200;
	double life = 150;
	double lifeMAX = 150;
	float lifebarRate;
	int lifeBarFillPerc;
	Resolution* res;
	GenericListObject* effects;
	SDL_Rect* lifebarlow;
	SDL_Rect* lifebarup;
};
