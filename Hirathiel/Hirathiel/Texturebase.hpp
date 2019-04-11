#pragma once
#include<SDL.h>
#include<string>


class Texture {
public:
	Texture(SDL_Renderer* renderer);
	~Texture();
	inline SDL_Texture* getPlayer() { return this->playerTexture; };
	inline SDL_Texture* getOrc() { return this->orcTexture; };
	inline SDL_Texture* getGrassland() { return this->Grassland; };

private:
	bool inittexture();
	SDL_Renderer* renderer;
	SDL_Texture* playerTexture;
	SDL_Texture* orcTexture;
	SDL_Texture* Grassland;
};