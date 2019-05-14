#include "Text.hpp"
#include <iostream>

Text::Text(SDL_Renderer* renderer,const std::string &fontPath, int fontSize, const std::string &text, const SDL_Color &color){
	texture = loadFont(renderer,fontPath, fontSize,text,color);
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
}

Text::~Text(){
}

void Text::display(int x, int y, SDL_Renderer* renderer) {

	rect.x = x;
	rect.y = y;

	SDL_RenderCopy(renderer, texture, nullptr, &rect);
}

 SDL_Texture *Text::loadFont(SDL_Renderer* renderer, const std::string &fontPath, int fontSize, const std::string &text, const SDL_Color &color) {
	 TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
	 if (!font) {
		 std::cerr << "Failed to load font\n";
	 }

	 auto textSurface = TTF_RenderText_Solid(font,text.c_str(),color);
	 if (!textSurface) {
		 std::cerr << "failed to create text surface\n";
	 }

	 auto textTexture = SDL_CreateTextureFromSurface(renderer,textSurface);
	 if (!textTexture) {
		 std::cerr << "failed to create text Texttexture\n";
	 }
	 SDL_FreeSurface(textSurface);
	 return textTexture;
}	
