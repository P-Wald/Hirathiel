#include "Strike.hpp"
#include <SDL.h>
#include <math.h>
#include "Poison.hpp"


Strike::Strike(int x, int y, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer, int critchance, float crit):CombatAction((x),(y),(rect),(texture),(renderer)){
	this->critchance = critchance;
	this->crit = crit;
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
	copy->copy(this->effects);
	Bleed* copy2 = new Bleed(5);
	copy2->copy(dynamic_cast<Effect*>(this->effects->getNext()));
	applicant->addEffect(copy);
	applicant->addEffect(copy2);
	copy = nullptr; copy2 = nullptr;
	delete copy, copy2;
}



void Strike::addEffects(){
	int dmg = 25;
	srand(time(NULL));
	if (rand() % 100 + 1 <= this->critchance) {
		dmg *= this->crit;
		printf("critted");
	}
	this->effects = new FlatDmg(dmg);
	this->effects->setNext(new Bleed(5));
}  
