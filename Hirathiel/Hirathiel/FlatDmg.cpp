#include "FlatDmg.hpp"
#include "MoB.hpp"


FlatDmg::FlatDmg(int dmg):Effect((NULL),(1)){
	this->dmg = dmg;
	this->ticks = 0;
	this->timing = 0;
}
FlatDmg::~FlatDmg() {}

void FlatDmg::copy(Effect* effect){
	FlatDmg* copy = dynamic_cast<FlatDmg*>(effect);
	if (copy) {
		this->timing = effect->getTiming();
		this->ticks = effect->getTicks();
		this->dmg = copy->getdmg();
	}
	copy = nullptr; delete copy;
	this->next = nullptr;
	this->prev = nullptr;
}

void FlatDmg::apply(Object* applicant) {
	dynamic_cast<MoB*>(applicant)->applyDmg(this->dmg);
	this->ticks--;
}