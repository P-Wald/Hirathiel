#pragma once
#include "Effect.hpp"

class FlatDmg:public Effect {
public:
	FlatDmg(int dmg);
	~FlatDmg();
	int getdmg() { return this->dmg; };
	void apply(MoB* applicant) override;
	void copy(Effect* effect) override;
protected:
	int dmg;
};