#include "Game.hpp"
#include <stdlib.h> 
#include <chrono>


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
	const std::string* title = new std::string("Kreutzers Game");
	this->window = new Window(*title, 1280, 720);

	this->renderer = window->getRenderer();
	if (this->renderer == nullptr) {
		std::cerr << "Error setting up renderer\nAborting\n";
		this->window->setRun(false);
	}

	this->textures = new Texture(this->renderer);

	this->object = new Object(0,0,0,0,this->renderer);
	this->player = new MoB(640, 360, 100, 100, this->renderer, this->textures->getPlayer());

	this->timer = new CTimer();
}




Game::~Game() {
	this->window->~Window();
	this->object->~Object();
	this->textures->~Texture();
	SDL_DestroyRenderer(this->renderer);
	printf("Released Memory");
}

bool Game::init() {
	return true;
}

void Game::runApp() {
	this->timer->update();
	while (this->window->getrun()) {
		//Prints out Time needed per Lap/per Frame
		std::cout << this->timer->getElapsed() << std::endl;

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		this->pollEvents(currentKeyStates);
		this->timer->update();
		this->drawObjects();

		this->window->clear(this->textures->getGrassland());

		this->spawn();
	}


}

void Game::drawObjects() {
	Object* current = this->object;
	while (current != nullptr) {
		current->draw();
		current = current->getNext();
	}
	delete current;
	this->player->draw();

}



void Game::spawn() {
	srand(time(NULL));
	if (rand() % 100 < 10) {
		Object* current = this->object;
		while (current->getNext() != NULL) {
			current = current->getNext();
		}
		current->addNext(new Object(rand() % 800, rand() % 600, 100, 100, this->renderer,this->textures->getOrc()));
	}
}
