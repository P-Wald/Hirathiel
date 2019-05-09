#include "Poison.hpp"

Poison::Poison(int time):Effect((time),(time/2)) {
	this->dmg = 15;
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
	this->next = nullptr;
	this->prev = nullptr;
}

void Poison::apply(MoB* applicant) {
	this->poisonTimer->updateElapsed();
	if (poisonTimer->getElapsed() >= 1) {
		applicant->applyDmg(this->dmg);
		this->timing - poisonTimer->getElapsed();
		this->poisonTimer->update();
		this->ticks--;
	}
}