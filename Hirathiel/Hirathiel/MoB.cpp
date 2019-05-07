#include "MoB.hpp"


MoB::MoB(int x, int y, int w, int h, SDL_Renderer *renderer):Object((x),(y),(w),(h),(renderer)),MobListObject(){
	this->initrect();
	this->init();
}

MoB::MoB(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture) : Object((x),(y),(w),(h),(renderer),(texture)), MobListObject() {
	this->initrect();
	this->init();
}

MoB::~MoB() {
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
	delete moveVector;
}



bool MoB::isHit(SDL_Rect* rect) {
	SDL_bool intersect = SDL_IntersectRect(this->rect, rect, nullptr);
	if (intersect == SDL_FALSE) {
		return false;
	}
	return true;
}