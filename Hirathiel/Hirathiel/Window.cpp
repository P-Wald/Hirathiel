#include "Window.hpp"
#include <SDL.h>
#include <iostream>
#include "Object.hpp"
#include <SDL_ttf.h>

Window::Window(const std::string &title, int w, int h) :title(title), w(w), h(h) {
	this->run = init();
}


Window::~Window() {
	SDL_DestroyWindow(this->window);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}


bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Error when initializing the SDL\n";
		return false;
	}

	if (IMG_Init(IMG_INIT_JPG) != 1) {
		std::cerr << "Failed to initialize image engine\n";
		return false;
	}

	if (TTF_Init() == -1) {
		std::cerr << "Failed to initialize Text engine\n";
		return false;
	}

	this->window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED
		, this->w, this->h,
		0
	);
	if (!window) {
		std::cerr << "Failed to create a window\n";
		return false;
	}

	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
	if (this->renderer == nullptr) {
		std::cerr << "Failed to create a renderer\n";
		return false;
	}

	return true;
}


void Window::pollEvents(SDL_Event *event) {
	
	switch (event->type) {
	case SDL_QUIT:
		this->run = false;
		break;
	case SDL_KEYDOWN:
		switch (event->key.keysym.sym) {
		case SDLK_ESCAPE:
			this->run = false;
			break;
		}
		break;
	}
	
}


void Window::clear(SDL_Texture* background)const {
	SDL_RenderPresent(this->renderer);
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 255, 255);
	SDL_RenderClear(this->renderer);
	SDL_Rect* backgroundRect = new SDL_Rect();
	backgroundRect->x = 0;
	backgroundRect->y = 0;
	backgroundRect->w = this->w;
	backgroundRect->h = this->h;
	SDL_RenderCopy(this->renderer, background, NULL, backgroundRect);
	delete backgroundRect;
}


