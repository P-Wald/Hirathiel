#pragma once

#include "Object.hpp"
#include "Window.hpp"
#include "Texturebase.hpp"
#include <iostream>
#include <list>
#include "Timer.hpp"
#include "MoB.hpp"
#include "Player.hpp"
#include "MobList.hpp"
#include <thread>

class Game {
public:
	Game();
	~Game();
	void runApp();

private:
	bool init();
	void pollEvents(const Uint8* keystate);
	void spawn();
private:
	int xres, yres;
	CTimer* timer;
	Texture* textures;
	SDL_Renderer* renderer;
	Window* window;
	Player* player;
	MobList* mobs;
};