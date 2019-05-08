#include "MoB.hpp"
#include "Effect.hpp"


MoB::MoB(int x, int y, int w, int h, SDL_Renderer *renderer):Object((x),(y),(w),(h),(renderer)),MobListObject(){
	this->initrect();
	this->init();
	this->res = nullptr;
	this->effects = nullptr;
}

MoB::MoB(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture) : Object((x),(y),(w),(h),(renderer),(texture)), MobListObject() {
	this->initrect();
	this->init();
	this->res = nullptr;
	this->effects = nullptr;
}

MoB::~MoB() {
	this->res = nullptr; 
	delete this->res;
	delete this->effects;
}

bool MoB::init()
{
	this->next = nullptr;
	this->prev = nullptr;
	this->id = 1;
	return true;
}

void MoB::move(Vector2D* moveVector) {
	this->x = this->x + moveVector->getX();
	this->y = this->y + moveVector->getY();

	boundaries();
	delete moveVector;
}

void MoB::boundaries() {
	if (this->x + this->w <= 0) {
		this->x = this->res->getW();
	}
	else {
		if (this->x >= this->res->getW()) {
			this->x = 0 - this->w;
		}
	}
	if (this->y + this->h <= 0) {
		this->y = this->res->getH();
	}
	else {
		if (this->y >= this->res->getH()) {
			this->y = 0 - this->h;
		}
	}
}


bool MoB::isHit(SDL_Rect* rect) {
	SDL_Rect* intersection = new SDL_Rect();
	SDL_bool intersect = SDL_IntersectRect(this->rect, rect, intersection);
	delete intersection;
	if (intersect == SDL_FALSE) {
		return false;
	}
	return true;
}

void MoB::setRes(Resolution* res) {
	this->res = res;
}

bool MoB::applyDmg(int dmg) {
	this->life -= dmg;
	if (this->life <= 0) {
		return true;
	}
	return false;
}

bool MoB::triggerEffects() {
	if (!effects) {
		return false;
	}
	Effect* current = dynamic_cast<Effect*>(effects);
	while (current) {
		current->apply(this);
		if (current->getTicks() == 0) {
			if (!current->getPrev()) {
				this->effects = dynamic_cast<Effect*>(current->getNext());
			}else {
				current->getPrev()->setNext(current->getNext());
				if (current->getNext()) {
					current->getNext()->setPrev(current->getPrev());
				}
			}

		}
		current = dynamic_cast<Effect*>(current->getNext());
	}
	if (this->life <= 0) {
		return true;
	}
	return false;
}

void MoB::addEffect(GenericListObject* effect) {
	if (!this->effects) {
		this->effects = effect;
		return;
	}
	GenericListObject* current = effects;
	while (current->getNext()) {
		current->getNext();
	}
	current->setNext(effect);
	effect->setPrev(current);
	
	current = nullptr;
	delete current;
}