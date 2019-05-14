#include "Cripple.hpp"
#include "MoB.hpp"

Cripple::Cripple(int time) :Effect((time), (1)) {
	this->slowTimer = new CTimer();
	this->firsttick = true;
	this->slow = 0.6;
	this->speedReduced = 0;
}

Cripple::~Cripple() {
	delete this->slowTimer;
}

void Cripple::apply(Object* applicant){
	this->slowTimer->updateElapsed();
	 
	if (this->firsttick) {
		double speed = dynamic_cast<MoB*>(applicant)->getSpeed();
		this->speedReduced = speed * this->slow;

		dynamic_cast<MoB*>(applicant)->setSpeed(speed - speedReduced);
		firsttick = false;
	}
	if (this->slowTimer->getElapsed() >= this->timing) {
		dynamic_cast<MoB*>(applicant)->setSpeed(dynamic_cast<MoB*>(applicant)->getSpeed() + this->speedReduced);
		this->ticks--;
	}
}

void Cripple::copy(Effect* effect){
	Cripple* copy = dynamic_cast<Cripple*>(effect);
	if (copy) {
		this->timing = copy->getTiming();
	}
	copy = nullptr; delete copy;
}