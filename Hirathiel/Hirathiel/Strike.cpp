#include "Strike.hpp"
#include <SDL.h>
#include <math.h>
#include "Poison.hpp"


Strike::Strike(MoBMetaData data, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer, int xpos, int ypos):CombatAction((x),(y),(rect),(texture),(renderer)){
	this->x = data.getX();
	this->y = data.getY();
	this->crit = data.getCritMultiplier();
	this->critchance = data.getCritChance();
	this->xpos = xpos;
	this->ypos = ypos;

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

	float scalar = 75 / length;


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
	FlatDmg* copy = new FlatDmg(25);
	copy->copy(this->effects.getObj(0));
	Bleed* copy2 = new Bleed(5);
	copy2->copy(this->effects.getObj(1));
	Knockback* copy3 = new Knockback(200,this->xpos,this->ypos);
	copy3->copy(this->effects.getObj(2));

	applicant->addEffect(copy);
	applicant->addEffect(copy2);
	applicant->addEffect(copy3);

	copy = nullptr; copy2 = nullptr; copy3 = nullptr;
	delete copy,copy2,copy3;
}



void Strike::addEffects(){
	int dmg = 25;
	srand(chrono::system_clock::now().time_since_epoch().count());
	if (rand() % 100 + 1 <= this->critchance) {
		dmg *= this->crit;
	}
	this->effects.add(new FlatDmg(dmg));
	this->effects.add(new Bleed(5));
	this->effects.add(new Knockback(200, this->xpos, this->ypos));
}

void Strike::settarget(int x, int y){
	this->targetx = x;
	this->targety = y;

	Vector2D* posVector = new Vector2D(this->targetx - this->x,this->targety - this->y);
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

	float scalar = 75 / length;


	posVector->scalar(scalar);
	this->x += posVector->getX();
	this->y += posVector->getY();
	this->rect->x = this->x;
	this->rect->y = this->y;

	delete posVector;
}
