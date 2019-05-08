#pragma once
#include "MoB.hpp"
#include "GenericListObject.hpp"

class Effect : public GenericListObject{
public:
	Effect(float timing, int ticks);
	~Effect();

	virtual void apply(MoB* applicant);
	int getTicks() { return this->ticks; };
protected:
	float timing;
	int ticks;
};