#include "MoB.hpp"
#include "Effect.hpp"


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
	this->lifebarlow = new SDL_Rect();
	this->lifebarup = new SDL_Rect();
	this->lifebarlow->h = 20;
	this->lifebarlow->w = 100;
	this->lifebarlow->x = this->x;
	this->lifebarlow->y = this->y-20;
	this->lifebarup->h = 20;
	this->lifebarup->w = this->lifebarlow->w;
	this->lifebarup->x = this->x;
	this->lifebarup->y = this->y - 20;

	this->lifebarRate = (lifebarlow->w) / this->lifeMAX;
	this->lifeBarFillPerc = (int)(this->life * this->lifebarRate);


	this->next = nullptr;
	this->prev = nullptr;
	this->id = 1;
	return true;
}

void MoB::setLife(int life, int lifeMAX) {
	if (life) {
		this->life = life;
	}if (lifeMAX) {
		this->lifeMAX = lifeMAX;
	}
	this->lifebarRate = (lifebarlow->w) / this->lifeMAX;
}

void MoB::move(Vector2D* moveVector) {
	if (moveVector) {
		this->poslock.lock();
		this->x = this->x + moveVector->getX();
		this->y = this->y + moveVector->getY();
		boundaries();

		this->poslock.unlock();

		this->updateLifeBar();
	}
	delete moveVector;
	this->update();
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

void MoB::updateLifeBar() {
	this->lifeBarFillPerc = (int)(this->life * this->lifebarRate);


	this->lifebarlow->x = this->x;
	this->lifebarlow->y = this->y-20;
	this->lifebarup->x = this->x;
	this->lifebarup->y = this->y-20;
	this->lifebarup->w = this->lifeBarFillPerc;
}



bool MoB::triggerEffects() {
	std::vector<Effect*> list = this->effects.get();
	for (int i = 0; i < list.size(); i++) {
		if (list.at(i)) {
			list.at(i)->apply(this);
			if (this->effects.getObj(i)->getTicks() <= 0) {
				this->effects.remove(i);
				i--;
				break;
			}
		}
	}


	if (this->life <= 0) {
		return true;
	}
	this->updateLifeBar();
	return false;
}




void MoB::addEffect(Effect* effect) {
	this->effects.add(effect);
}

void MoB::lifebar() {
	SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(this->renderer, this->lifebarlow);

	SDL_SetRenderDrawColor(this->renderer, 0, 190, 0, 255);
	SDL_RenderFillRect(this->renderer, this->lifebarup);
}
