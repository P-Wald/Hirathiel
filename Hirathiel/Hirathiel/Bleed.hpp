#pragma once

#include "Effect.hpp"

class Bleed :public Effect {
public:
	Bleed(int time);
	~Bleed();
	void apply(Object* applicant) override;
	void copy(Effect* effect) override;
	bool getFirstTick() { return firsttick; };
	int getDmg() { return dmg; };

	void init();
private:
	bool firsttick;
	int dmg;
	CTimer* bleedTimer;
};
