#include "Effect.hpp"


Effect::Effect(float timing, int ticks):GenericListObject() {
	this->timing = timing;
	this->ticks = ticks;
}


Effect::~Effect(){
}

void Effect::copy(Effect* effect) {
	
}

void Effect::apply(Object* applicant){

}