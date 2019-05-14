#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text {
public:
	Text(SDL_Renderer* renderer,const std::string &fontPath,int fontSize, const std::string &text, const SDL_Color &color);
	~Text();
	void display(int x, int y, SDL_Renderer* renderer);
	 
	static SDL_Texture* loadFont(SDL_Renderer* renderer, const std::string &fontPath, int fontSize, const std::string &text, const SDL_Color &color);
private:
	SDL_Texture* texture = nullptr;
	SDL_Rect rect;
};