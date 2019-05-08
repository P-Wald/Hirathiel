#include "Player.hpp"

Player::Player(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Texture* texture):MoB((x),(y),(w),(h),(renderer),(texture)){
	this->speed = 400;
	this->life = 100;
	this->angle = 0;
}

Player::~Player(){}


CombatAction* Player::pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer){
	CombatAction* combat = nullptr;
	if (this == nullptr) {
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
		switch (event->type) {
			case SDL_MOUSEMOTION:
				angle = atan2(event->motion.y - (this->y + this->h), event->motion.x - (this->x + this->w));

				angle = angle * (180 / M_PI);
				if (angle < 0) {
					angle = 360 - (-angle);
				}
				this->angle = angle;
				break;
		
			case SDL_KEYDOWN:
				switch (event->key.keysym.sym) {
				case SDLK_1:
					SDL_Rect* rect = new SDL_Rect();
					rect->h = 50;
					rect->w = 50;
					rect->x = this->x+this->w/2-25;
					rect->y = this->y+this->h/2-25;
					combat = new Strike(this->x + this->w /2-25,this->y+this->h/2-25, rect, nullptr, this->renderer);
					break;
				}
			break;
		}
	}

	this->update();
	return combat;
}