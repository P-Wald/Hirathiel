#include "MeleeWeapon.hpp"

MeleeWeapon::MeleeWeapon(int x, int y, SDL_Renderer* renderer, SDL_Texture* texture) :Weapon((x), (y), (renderer), (texture)) {
	this->type = 1;
}
