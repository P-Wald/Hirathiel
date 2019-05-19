#pragma once

class Combatstats {
public:
	Combatstats(int level,int type);
	int getAttack() { return this->attack; };
	int getCritChance() { return this->critchance; };
	int getCrit() { return this->crit; };
	int getArmor() { return this->armor; };
	int getRange() { return this->range; };
	void setRange(int range) { this->range = range; };
	void setAttack(int attack) { this->attack = attack; };
	void setCritChance(int critchance) { this->critchance = critchance; };
	void setCrit(float crit) { this->crit = crit; };
	void setArmor(int armor) { this->armor = armor; };
	void update(int level);

private:
	int range;
	int type;
	int attack;
	int critchance;
	float crit;
	int armor;
};