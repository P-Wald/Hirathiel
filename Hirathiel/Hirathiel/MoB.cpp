#include "MoB.hpp"


MoB::MoB(int x, int y, int w, int h, SDL_Renderer *renderer):Object((x),(y),(w),(h),(renderer)),MobListObject(){
	this->initrect();
	this->init();
	this->res = nullptr;
}

MoB::MoB(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture) : Object((x),(y),(w),(h),(renderer),(texture)), MobListObject() {
	this->initrect();
	this->init();
	this->res = nullptr;
}

MoB::~MoB() {
	this->res = nullptr; 
	delete this->res;
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

	//boundaries();
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