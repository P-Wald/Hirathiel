#include "Poison.hpp"
#include "MoB.hpp"

Poison::Poison(int time):Effect((time),(time/2)) {
	this->dmg = 5;
	this->poisonTimer = new CTimer();
}

Poison::~Poison() {
	delete this->poisonTimer;
}

void Poison::copy(Effect* effect) {
	Poison* copy = dynamic_cast<Poison*>(effect);
	if (copy) {
		this->timing = effect->getTiming();
		
		this->ticks = effect->getTicks();
	}
	copy = nullptr; delete copy;
}

void Poison::apply(Object* applicant) {
	this->poisonTimer->updateElapsed();
	if (poisonTimer->getElapsed() >= 2) {
		dynamic_cast<MoB*>(applicant)->applyDmg(this->dmg);
		this->timing - poisonTimer->getElapsed();
		this->poisonTimer->update();
		this->ticks--;
	}
}