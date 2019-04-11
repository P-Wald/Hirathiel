#include <SDL_image.h>
#include "Texturebase.hpp"
#include <string>
#include <iostream>

Texture::Texture(SDL_Renderer* renderer) :renderer(renderer) {
	std::string* path = new std::string("res/Player.png");
	this->inittexture(path);
	delete path;

}

Texture::~Texture() {
	SDL_DestroyTexture(this->playerTexture);
}


bool Texture::inittexture(std::string* path) {
	auto surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
		return false;
	}

	this->playerTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->playerTexture) {
		std::cerr << "Failed to create texture. \n";
		return false;
	}
	SDL_FreeSurface(surface);
	return true;
}