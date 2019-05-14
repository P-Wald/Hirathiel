#pragma once
#include "Effect.hpp"

class Cripple :public Effect {
public:
	Cripple(int time);
	~Cripple();
	void apply(Object* applicant) override;
	void copy(Effect* effect) override;
	bool getFirstTick() { return this->firsttick; };
private:
	bool firsttick;
	float slow;
	CTimer* slowTimer;
	double speedReduced;
};