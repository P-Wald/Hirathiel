#include "Player.hpp"

Player::Player(int x, int y, int w, int h, SDL_Renderer* renderer, SDL_Texture* texture):MoB((x),(y),(w),(h),(renderer),(texture)){
	this->speed = 400;
	this->life = 100;
}

Player::~Player(){}

void Player::pollEvents(SDL_Event* event, const Uint8* keystate, CTimer* timer){
	if (this == nullptr) {
		return;
	}

	Vector2D* vector = new Vector2D(0.0f, 0.0f);

	if (keystate[SDL_SCANCODE_W]) {
		vector->subVector(new Vector2D(0, timer->getElapsed() * this->speed));
	}if (keystate[SDL_SCANCODE_S]) {
		vector->addVector(new Vector2D(0, timer->getElapsed() * this->speed));
	}if (keystate[SDL_SCANCODE_A]) {
		vector->subVector(new Vector2D(timer->getElapsed() * this->speed, 0));
	}if (keystate[SDL_SCANCODE_D]) {
		vector->addVector(new Vector2D(timer->getElapsed() * this->speed, 0));
	}

	this->move(vector);

	if (event != nullptr) {
		switch (event->type) {
		case SDL_MOUSEMOTION:
			float angle = atan2(event->motion.y - (this->y + this->h), event->motion.x - (this->x + this->w));

			angle = angle * (180 / M_PI);
			if (angle < 0) {
				angle = 360 - (-angle);
			}
			this->angle = angle + 90;
			break;
		}
	}

	this->update();
}