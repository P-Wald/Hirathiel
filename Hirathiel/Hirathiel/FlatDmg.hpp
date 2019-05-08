#pragma once
#include "Effect.hpp"

class FlatDmg:public Effect {
public:
	FlatDmg(int dmg);
	~FlatDmg();
	void apply(MoB* applicant) override;
protected:
	int dmg;
};