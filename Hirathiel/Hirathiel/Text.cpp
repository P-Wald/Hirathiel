#include "Text.hpp"
#include <iostream>

Text::Text(SDL_Renderer* renderer, const std::string& fontPath, int fontSize, const SDL_Color& color) {
	this->font = TTF_OpenFont(fontPath.c_str(), fontSize);
	this->color = color;
	this->renderer = renderer;
	this->text = "";
	if (!font) {
		std::cerr << "Failed to load font\n";
	}
}

Text::~Text() {
	texture = nullptr;
	font = nullptr;
	renderer = nullptr;
	delete texture;
	delete font;
	delete renderer;
}

void Text::display(int x, int y) {

	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);

	SDL_RenderCopy(this->renderer, texture, nullptr, &rect);
}

void Text::setText(std::string& text)
{
	this->text = text;

	auto textSurface = TTF_RenderText_Solid(font, text.c_str(), color);
	if (!textSurface) {
		std::cerr << "failed to create text surface\n";
	}
	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	if (!textTexture) {
		std::cerr << "failed to create text Texttexture\n";
	}
	SDL_DestroyTexture(this->texture);
	texture = textTexture;
	textTexture = nullptr;
	delete textTexture;
	SDL_FreeSurface(textSurface);
}



