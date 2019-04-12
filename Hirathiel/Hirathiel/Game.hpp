#pragma once

#include "Object.hpp"
#include "Window.hpp"
#include "Texturebase.hpp"
#include <iostream>
#include <list>
#include "Timer.hpp"
#include "MoB.hpp"

class Game {
public:
	Game();
	~Game();
	void runApp();

private:
	bool init();
	void pollEvents(const Uint8* keystate);
	void spawn();
	void drawObjects();
private:
	CTimer* timer;
	Texture* textures;
	SDL_Renderer* renderer;
	Window* window;
	MoB* player;
	Object* object;
};