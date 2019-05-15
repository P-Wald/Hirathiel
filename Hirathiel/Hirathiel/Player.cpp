#include "Player.hpp"
#include "MoBMetaData.hpp"

Player::Player(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Texture* texture):MoB((x),(y),(w),(h),(renderer),(texture)){
	this->speed = 400;
	this->angle = 0;
	this->life = 100;
	this->lifeMAX = 100;
	this->faction = 0;

}

Player::~Player(){}


CombatAction* Player::pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer){
	CombatAction* combat = nullptr;
	if (!this) {
		return combat;
	}

	Vector2D* vector = new Vector2D(0.0f, 0.0f);

	if (keystate[SDL_SCANCODE_W]) {
		vector->subVector(new Vector2D(0,this->speed));
	}if (keystate[SDL_SCANCODE_S]) {
		vector->addVector(new Vector2D(0,this->speed));
	}if (keystate[SDL_SCANCODE_A]) {
		vector->subVector(new Vector2D(this->speed, 0));
	}if (keystate[SDL_SCANCODE_D]) {
		vector->addVector(new Vector2D(this->speed, 0));
	}
	vector->scalar(timer->getElapsed());

	this->move(vector);
	float angle;

	if (event != nullptr) {
		SDL_Rect* rect = new SDL_Rect();
		MoBMetaData data = MoBMetaData(this->x + this->w/2, this->y+this->h/2, this->w, this->h, 20, 1.5);
		Strike* strike;
		switch (event->type) {
			case SDL_MOUSEMOTION:
				angle = atan2(event->motion.y - (this->y + this->h/2), event->motion.x - (this->x + this->w/2));

				angle = angle * (180 / M_PI);
				if (angle < 0) {
					angle = 360 - (-angle);
				}
				this->angle = angle;
				break;
		
			case SDL_MOUSEBUTTONDOWN:
				switch (event->button.button){
				case SDL_BUTTON_LEFT:
					rect->h = 50;
					rect->w = 50;
					rect->x = this->x+this->w/2-25;
					rect->y = this->y+this->h/2-25;
					
					combat = new Strike(data, rect, nullptr, this->renderer,this->x+(this->w/2),this->y+(this->h/2));
					combat->setFaction(1);
					strike = nullptr; delete strike;
					break;
				case SDL_BUTTON_RIGHT:
					rect->h = 50;
					rect->w = 50;
					rect->x = this->x + this->w / 2 - 25;
					rect->y = this->y + this->h / 2 - 25;
					combat = new HiddenDagger(this->x + this->w / 2 - 25, this->y + this->h / 2 - 25, rect, nullptr, this->renderer,40,2);
					combat->setFaction(1);
					break;
				}
			break;
		}
		rect = nullptr; delete rect;
	}
	this->update();
	return combat;
}

bool Player::triggerEffects()
{
	auto list = this->effects.get();
	for (int i = 0; i < list.size(); i++) {
		list.at(i)->apply(this);
	}
	for (int i = 0; i < list.size(); i++) {
		if (list.at(i)->getTicks() <= 0) {
			this->effects.remove(i);
		}
	}

	return false;
}
