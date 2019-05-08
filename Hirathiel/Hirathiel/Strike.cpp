#include "Strike.hpp"

Strike::Strike(int x, int y, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer):CombatAction((x),(y),(rect),(texture),(renderer)){
	this->addEffects();
}
Strike::~Strike() {}


void Strike::applyEffects(MoB* applicant){
	applicant->addEffect(this->effects);
}

void Strike::addEffects(){
	this->effects = new FlatDmg(25);
}