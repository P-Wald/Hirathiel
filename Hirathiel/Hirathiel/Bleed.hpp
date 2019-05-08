#pragma once

#include "Effect.hpp"

class Bleed :public Effect {
public:
	Bleed(int dmg,int time);
	~Bleed();
	void apply(MoB* applicant) override;
	void init();
private:
	bool firsttick;
	int dmg;
	CTimer* bleedTimer;
};
