#include "Weapon.hpp"

Weapon::Weapon(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :GearItem((x), (y), (renderer), texture) {
}

void Weapon::equip(MoB* applicant) {
	applicant->stats->setAttack(applicant->stats->getAttack() + this->attackBonus);
	applicant->stats->setCritChance(applicant->stats->getCritChance() + this->critchance);
	applicant->stats->setCrit(applicant->stats->getCrit() + this->crit);
	apply(applicant);
}

void Weapon::unequip(MoB* applicant) {
	applicant->stats->setAttack(applicant->stats->getAttack() - this->attackBonus);
	applicant->stats->setCritChance(applicant->stats->getCritChance() - this->critchance);
	applicant->stats->setCrit(applicant->stats->getCrit() - this->crit);
	unapply(applicant);
}
