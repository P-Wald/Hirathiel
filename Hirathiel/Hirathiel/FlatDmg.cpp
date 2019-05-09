#include "FlatDmg.hpp"


FlatDmg::FlatDmg(int dmg):Effect((NULL),(1)){
	this->dmg = dmg;
}
FlatDmg::~FlatDmg() {}

void FlatDmg::copy(Effect* effect){
	FlatDmg* copy = dynamic_cast<FlatDmg*>(effect);
	if (copy) {
		this->dmg = copy->getdmg();
	}
	copy = nullptr; delete copy;
	this->next = nullptr;
	this->prev = nullptr;
}

void FlatDmg::apply(MoB* applicant) {
	applicant->applyDmg(this->dmg);
	this->ticks--;
}