#include <SDL_image.h>
#include "Texturebase.hpp"
#include <string>
#include <iostream>

Texture::Texture(SDL_Renderer* renderer) :renderer(renderer) {	
	if (this->inittexture()) {
		printf("Initialization of Textures was successful \n");
	}
	else {
		printf("Initialization of Textures was unsuccessful. Some Objects might not have Textures!\n");
	}
}

Texture::~Texture() {
	SDL_DestroyTexture(this->playerTexture);
}


bool Texture::inittexture() {
	bool success = true;
	std::string* path = new std::string("res/Player.png");

	auto surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->playerTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->playerTexture) {
		std::cerr << "Failed to create Players texture. \n";
		success = false;
	}
	


	path = new std::string("res/Orc.png");
	surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->orcTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->orcTexture) {
		std::cerr << "Failed to create Orc texture. \n";
		success = false;
	}

	path = new std::string("res/GrasslandBackground.jpg");
	surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->Grassland = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->Grassland) {
		std::cerr << "Failed to create Grassland texture. \n";
		success = false;
	}

	path = new std::string("res/BronzeCoin.png");
	surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->bronzecoin = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->bronzecoin) {
		std::cerr << "Failed to create Grassland texture. \n";
		success = false;
	}

	path = new std::string("res/SilverCoin.png");
	surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->silverCoin = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->silverCoin) {
		std::cerr << "Failed to create Grassland texture. \n";
		success = false;
	}

	path = new std::string("res/GoldCoin.png");
	surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->goldCoin = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->goldCoin) {
		std::cerr << "Failed to create Grassland texture. \n";
		success = false;
	}

	path = new std::string("res/IronSword.png");
	surface = IMG_Load(path->c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	this->ironSword = SDL_CreateTextureFromSurface(this->renderer, surface);
	if (!this->ironSword) {
		std::cerr << "Failed to create Grassland texture. \n";
		success = false;
	}


	SDL_FreeSurface(surface);
	delete path;
	return success;
}