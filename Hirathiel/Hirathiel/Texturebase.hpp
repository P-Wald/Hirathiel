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
	inline SDL_Texture* getBronzeCoin() { return this->bronzecoin; };
	inline SDL_Texture* getSilverCoin() { return this->silverCoin; };
	inline SDL_Texture* getGoldCoin() { return this->goldCoin; };
	inline SDL_Texture* getIronSword() { return this->ironSword; };
private:
	bool inittexture();
	SDL_Renderer* renderer;
	SDL_Texture* playerTexture;
	SDL_Texture* orcTexture;
	SDL_Texture* Grassland;
	SDL_Texture* bronzecoin;
	SDL_Texture* silverCoin;
	SDL_Texture* goldCoin;
	SDL_Texture* ironSword;
};