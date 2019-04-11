#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>


class Window {
public:
	Window(const std::string &title, int w, int h);
	~Window();
	inline bool getrun() { return run; };
	void pollEvents(SDL_Event *event);
	void clear(SDL_Texture* background)const;
	void setRun(bool run) { this->run = run; };
	inline SDL_Renderer* getRenderer() { return this->renderer; };

	SDL_Window* getWindow() { return this->window; };

private:
	bool init();


private:


	std::string title;
	int w = 800, h = 600;
	bool run = false;

	SDL_Window *window = nullptr;
	SDL_Renderer *renderer = nullptr;


};