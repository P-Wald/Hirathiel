#include "Strike.hpp"
#include <SDL.h>
#include <math.h>

Strike::Strike(int x, int y, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer):CombatAction((x),(y),(rect),(texture),(renderer)){
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);

	Vector2D* posVector = new Vector2D(mouseX - this->x, mouseY - this->y);
	int sqX, sqY;
	sqX = (int)posVector->getX();
	sqY = (int)posVector->getY();
	if (sqX < 0)
		sqX *= -1;
	if (sqY < 0)
		sqY *= -1;
	sqX *= sqX;
	sqY *= sqY;

	float length = sqrt(sqX + sqY);
	//std::cout << length << std::endl;

	float scalar = 100 / length;


	posVector->scalar(scalar);
	this->x += posVector->getX();
	this->y += posVector->getY();
	this->rect->x = this->x;
	this->rect->y = this->y;

	delete posVector;

	this->addEffects();

}
Strike::~Strike() {}


void Strike::applyEffects(MoB* applicant){
	applicant->addEffect(this->effects);
}

void Strike::addEffects(){
	this->effects = new FlatDmg(25);
	this->effects->setNext(new Bleed(5,10));
}
