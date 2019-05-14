#pragma once
#include "Object.hpp"
#include "GenericListObject.hpp"

class Effect : public GenericListObject{
public:
	Effect(float timing, int ticks);
	~Effect();
	virtual void copy(Effect* effect);
	virtual void apply(Object* applicant);
	float getTiming() { return this->timing; };
	int getTicks() { return this->ticks; };
protected:
	float timing;
	int ticks;
};