#include "Game.hpp"
#include <stdlib.h> 
#include <chrono>
#include "Cripple.hpp"


MobList* moblist;
Resolution* res;
Player* player;
void Game::pollEvents(const Uint8* keystate) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		CombatAction* action = this->player->pollEvents(&event, keystate, this->timer);
		if (action) {
			actions->add(action);
		}
		action = nullptr; delete action;

		this->window->pollEvents(&event);
	}
	else {
		this->player->pollEvents(nullptr, keystate, this->timer);
	}
}
	
Game::Game() {
	this->actions = new CombatActionList();
	this->res = new Resolution(1280,720);
	res = this->res;
	const std::string* title = new std::string("Kreutzers Game");
	this->window = new Window(*title, this->res->getW() ,this->res->getH());

	this->renderer = window->getRenderer();
	if (this->renderer == nullptr) {
		std::cerr << "Error setting up renderer\nAborting\n";
		this->window->setRun(false);
	}

	this->textures = new Texture(this->renderer);

	this->mobs = new MobList();
	this->player = new Player(640, 360, 100, 100, this->renderer, this->textures->getPlayer());
	this->player->setRes(this->res);

	this->timer = new CTimer();
	moblist = this->mobs;
}

void aiThread()
{
	CTimer* aiTimer = new CTimer();
	MoB* current;
	GenericListObject* mob;
	
	while (true) {
		aiTimer->update();
		mob = moblist->getFirst()->getNext();
		while (mob) {
			current = dynamic_cast<MoB*>(mob);
			Vector2D* vector = new Vector2D(0.0f, 0.0f);
			/*int xP = player->getX(); 
			int xC = current->getX();
			int yP = player->getY(); 
			int yC = current->getY();
			int movX = xP - xC;
			int movY = yP - yC;*/
			//cout << player->getX();
			


			vector->addVector(new Vector2D(aiTimer->getElapsed() * current->getSpeed(), aiTimer->getElapsed() * current->getSpeed()));

			if (current) {
				current->move(vector);
				cout << aiTimer->getElapsed()<<endl;
			}


			mob = mob->getNext();
		}
	}
}



Game::~Game() {
	this->window->~Window();
	this->mobs->~MobList();
	delete this->res;
	this->textures->~Texture();
	SDL_DestroyRenderer(this->renderer);
}

bool Game::init() {
	return true;
}

void Game::runApp() {
	this->timer->update();
	int i = 0;
	time_t start = time(NULL);
	bool spawned = false;
	player = this->player;
	std::thread AI (aiThread);
	AI.detach();
	while (this->window->getrun()) {
		
		this->timer->update();
		if (time(NULL) - start >= 1) {
			start = time(NULL);
			std::cout << i << std::endl;
			i = 0;
		}
		//Prints out Time needed per Lap/per Frame
		//std::cout << this->timer->getElapsed() << std::endl;
		if (!spawned){
			this->spawn();
			spawned = true;
		}

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		this->pollEvents(currentKeyStates);


		this->mobs->hit(dynamic_cast<CombatAction*>(this->actions->getFirst()), 100);
		this->mobs->draw();
		this->player->triggerEffects();
		this->player->draw();
		this->actions->draw();
		this->window->clear(this->textures->getGrassland());
		this->mobs->triggerEffects();
		this->actions->clear();
		i++;
	}
}

void Game::spawn() {
	MoB* mob = new MoB(100, 100, 100, 100, this->renderer, this->textures->getOrc());
	mob->setRes(this->res);
	this->mobs->add(mob);
	mob = nullptr;
	delete mob;

}


