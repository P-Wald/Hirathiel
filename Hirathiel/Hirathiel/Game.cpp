#include "Game.hpp"
#include <stdlib.h> 
#include <chrono>


MobList* moblist;

void Game::pollEvents(const Uint8* keystate) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		this->player->pollEvents(&event, keystate, this->timer);
		this->window->pollEvents(&event);
	}
	else {
		this->player->pollEvents(nullptr, keystate, this->timer);
	}
}
	
Game::Game() {
	this->xres = 1280;
	this->yres = 720;
	const std::string* title = new std::string("Kreutzers Game");
	this->window = new Window(*title, this->xres, this->yres);

	this->renderer = window->getRenderer();
	if (this->renderer == nullptr) {
		std::cerr << "Error setting up renderer\nAborting\n";
		this->window->setRun(false);
	}

	this->textures = new Texture(this->renderer);

	this->mobs = new MobList();
	this->player = new Player(640, 360, 100, 100, this->renderer, this->textures->getPlayer());

	this->timer = new CTimer();
	moblist = this->mobs;
}




Game::~Game() {
	this->window->~Window();
	this->mobs->~MobList();
	this->textures->~Texture();
	SDL_DestroyRenderer(this->renderer);
}

bool Game::init() {
	return true;
}

void aiThread() {

}

void Game::runApp() {
	this->timer->update();
	int i = 0;
	time_t start = time(NULL);

	std::thread AI(aiThread);
	AI.detach();
	while (this->window->getrun()) {
		if (time(NULL) - start >= 1) {
			start = time(NULL);
			std::cout << i << std::endl;
			i = 0;
		}
		//
		//Prints out Time needed per Lap/per Frame
		//std::cout << this->timer->getElapsed() << std::endl;

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		this->pollEvents(currentKeyStates);
		this->timer->update();
		this->player->draw();
		this->mobs->draw();

		this->window->clear(this->textures->getGrassland());

		this->spawn();
		i++;
	}


}




void Game::spawn() {
	srand(time(NULL));
	if (rand() % 100 < 50) {
		MoB* enemy = new MoB(rand() % this->xres, rand() % this->yres, 100, 100, this->renderer, this->textures->getOrc());
		mobs->add(dynamic_cast<MobListObject*>(enemy));
	}
}
