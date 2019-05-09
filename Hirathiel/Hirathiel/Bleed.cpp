#include "Bleed.hpp"

Bleed::Bleed(int dmg,int time) :Effect((time), ((int)(time/1))) {
	this->dmg = dmg;
	this->bleedTimer = new CTimer();
	this->firsttick = true;
}

void Bleed::init() {
	
}


Bleed::~Bleed() {
	delete this->bleedTimer;
}

void Bleed::copy(Effect* effect){
	Bleed* copy = dynamic_cast<Bleed*>(effect);
	if (copy) {
		this->dmg = copy->getDmg();
	}
	copy = nullptr; delete copy;
	this->next = nullptr;
	this->prev = nullptr;
}

void Bleed::apply(MoB* applicant){
	this->bleedTimer->updateElapsed();
	if (bleedTimer->getElapsed() >= 1 && ticks > 0) {
		applicant->applyDmg(this->dmg);
		this->ticks--;
		this->timing - bleedTimer->getElapsed();
		this->bleedTimer->update();
	}
}