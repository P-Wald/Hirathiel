#pragma once
#include<SDL.h>
#include<string>


class Texture {
public:
	Texture(SDL_Renderer* renderer);
	~Texture();
	inline SDL_Texture* getPlayer() { return this->playerTexture; };

private:
	bool inittexture(std::string* path);
	SDL_Renderer* renderer;
	SDL_Texture* playerTexture;
};