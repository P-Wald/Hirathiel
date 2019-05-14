#include "CombatAction.hpp"

CombatAction::CombatAction(int x, int y, SDL_Rect* rect, SDL_Texture* texture, SDL_Renderer* renderer) {
	this->x = x;
	this->y = y;
	this->h = h;
	this->w = w;
	this->rect = rect;
	this->texture = texture;
	this->renderer = renderer;
	this->effects = nullptr;
	this->faction = 0;
}

CombatAction::CombatAction() {
	this->x = NULL;
	this->y = NULL;
	this->h = NULL;
	this->w = NULL;
	this->rect = nullptr;
	this->texture = nullptr;
	this->renderer = nullptr;
	this->effects = nullptr;
	this->faction = 0;
}

CombatAction::~CombatAction() {
	this->rect = nullptr;
	this->texture = nullptr;
	this->renderer = nullptr;
	delete rect;
	delete texture;
	delete renderer;
}

void CombatAction::draw() {
	if (texture && renderer) {
		if (SDL_RenderCopyEx(this->renderer, this->texture, nullptr, this->rect, this->angle, nullptr, SDL_FLIP_NONE) != 0) {
			std::cerr << "Could not render texture\n";
		};
	}
	// Attack debug mode, replace normal render to display attacks as red squares, (comment out clear function to see hitscans as well)
	SDL_SetRenderDrawColor(this->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(this->renderer, this->rect);

}
