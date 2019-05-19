#include "Sword.hpp"

Sword::Sword(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :MeleeWeapon((x), (y), (renderer), (texture)) {
	this->range = 75;
}