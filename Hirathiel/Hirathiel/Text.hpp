#pragma once

#include <SDL_ttf.h>
#include <SDL.h>
#include <string>

class Text {
public:
	Text(SDL_Renderer* renderer, const std::string& fontPath, int fontSize, const SDL_Color& color);
	~Text();
	void display(int x, int y);
	void setText(std::string& text);

private:
	SDL_Texture* texture = nullptr;
	SDL_Rect rect;
	TTF_Font* font;
	SDL_Color color;
	SDL_Renderer* renderer;
	std::string text;
};