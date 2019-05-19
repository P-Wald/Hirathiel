#include "CombatStats.hpp"

Combatstats::Combatstats(int level,int type) {
	this->attack = 40*level;
	this->critchance = level;
	this->crit = 1.0+(level/10);
	this->armor = 0+level;
	this->type = type;
	this->range = 0;
}

void Combatstats::update(int level) {
	this->attack += 40 * level;
	this->critchance += level;
	this->crit += (level / 10);
	this->armor += level;
}