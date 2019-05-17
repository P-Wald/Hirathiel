#pragma once

#include "Object.hpp"
#include "Window.hpp"
#include "Texturebase.hpp"
#include <iostream>
#include "Timer.hpp"
#include "MoB.hpp"
#include "Player.hpp"
#include "MobList.hpp"
#include "Resolution.hpp"
#include "CombatActionList.hpp"
#include "Text.hpp"
#include "ItemList.hpp"
#include "GameField.hpp"

class Game {
public:
	Game();
	~Game();
	void runApp();
	bool getRun() { return this->window->getrun(); };
	
private:
	bool init();
	void pollEvents(const Uint8* keystate);
	void spawn();
	void aiThread(CTimer* aiTimer);
	
private:
	CombatActionList* actions;
	Resolution* res;
	CTimer* timer;
	Texture* textures;
	SDL_Renderer* renderer;
	Window* window;
	Player* player;
	MobList* mobs;
	ItemList* items;
	GameField* field;

	bool respawn;
	float cd;
};