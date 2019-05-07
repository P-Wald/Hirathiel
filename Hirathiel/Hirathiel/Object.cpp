#include"Object.hpp"
#include <cmath>
#include <math.h>
#include <chrono>


Object::Object(int x, int y, int w, int h, SDL_Renderer *renderer) : x(x), y(y), w(w), h(h), renderer(renderer) {
	this->initrect();

}

Object::Object(int x, int y, int w, int h, SDL_Renderer *renderer, SDL_Texture* texture) : x(x), y(y), w(w), h(h), renderer(renderer), texture(texture)
{
	this->rect = new SDL_Rect();
	initrect();
}

void Object::initrect() {
	this->rect = new SDL_Rect();
	if (!init()) {
		this->rect->x = 0;
		this->rect->y = 0;
		this->rect->w = 10;
		this->rect->h = 10;
	}
	this->rect->x = x;
	this->rect->y = y;
	this->rect->w = w;
	this->rect->h = h;
}

Object::~Object() {
	SDL_DestroyTexture(this->texture);
}

bool Object::init() {
	return true;
}

void Object::draw() {
	if (this->texture != nullptr) {
		if (SDL_RenderCopyEx(this->renderer, this->texture, nullptr, this->rect, this->angle, nullptr, SDL_FLIP_NONE) != 0) {
			std::cerr << "Could not render texture\n";
		};
	}
	else {
		SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(this->renderer, this->rect);
	}
	return;
}
void Object::update() {
	if (!this->rect) {
		return;
	}
	this->rect->x = this->x;
	this->rect->y = this->y;
	this->rect->w = this->w;
	this->rect->h = this->h;
}

