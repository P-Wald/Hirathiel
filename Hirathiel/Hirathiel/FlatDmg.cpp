#include "FlatDmg.hpp"


FlatDmg::FlatDmg(int dmg):Effect((NULL),(1)){
	this->dmg = dmg;
}
FlatDmg::~FlatDmg() {}

void FlatDmg::apply(MoB* applicant) {
	applicant->applyDmg(this->dmg);
	this->ticks--;
}