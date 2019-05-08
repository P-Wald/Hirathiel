#include "Effect.hpp"


Effect::Effect(float timing, int ticks):GenericListObject() {
	this->timing = timing;
	this->ticks = ticks;
}

Effect::~Effect(){
}

void Effect::apply(MoB* applicant){

}