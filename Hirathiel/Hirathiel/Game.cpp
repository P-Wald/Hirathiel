#include "Game.hpp"
#include <stdlib.h> 
#include <chrono>
#include "Cripple.hpp"
#include <mutex>


MobList* moblist;
Resolution* res;
Player* player = nullptr;
std::mutex* MoBLock = new std::mutex();
Game* game;

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
	game = this;
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
	player = this->player;

	this->timer = new CTimer();
	moblist = this->mobs;
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
	srand(chrono::system_clock::now().time_since_epoch().count());
	this->timer->update();
	int i = 0;
	time_t start = time(NULL);
	bool spawned = false;
	while (this->window->getrun()) {
		if (!this->player) {
			break;
		}
		
		this->timer->update();
		if (time(NULL) - start >= 1) {
			start = time(NULL);
			//std::cout << i << std::endl;
			i = 0;
		}
		//Prints out Time needed per Lap/per Frame
		//std::cout << this->timer->getElapsed() << std::endl;
		if (!spawned){
			this->spawn();
			spawned = true;
		}if (!mobs->getFirst()->getNext()) {
			spawned = false;
		}

		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		this->pollEvents(currentKeyStates);


		this->mobs->hit(dynamic_cast<CombatAction*>(this->actions->getFirst()), 100);
		this->mobs->draw();
		this->player->triggerEffects();
		this->mobs->triggerEffects(MoBLock);
		this->player->draw();
		this->actions->draw();
		this->window->clear(this->textures->getGrassland());
		if (mobs->getFirst()->getNext()) {
			this->aiThread(this->timer);
		}
		this->actions->clear();
		i++;
	}
}

void Game::spawn() {
	MoB* mob = new MoB(rand()%this->res->getW(), rand()%this->res->getH(), 100, 100, this->renderer, this->textures->getOrc());
	mob->setRes(this->res);
	this->mobs->add(mob);
	mob = nullptr;
	delete mob;

	MoB* mob2 = new MoB(rand() % this->res->getW(), rand() % this->res->getH(), 100, 100, this->renderer, this->textures->getOrc());
	mob2->setRes(this->res);
	this->mobs->add(mob2);
	mob2 = nullptr;
	delete mob2;

}




void Game::aiThread(CTimer* aiTimer){
	MoB* current = nullptr;
	GenericListObject* mob;
	mob = moblist->getFirst();

	while (mob) {
			current = dynamic_cast<MoB*>(mob);
			if (current) {
			Vector2D* vector = new Vector2D(this->player->getX()-current->getX(),this->player->getY()- current->getY());
			int a, b; a = vector->getX(); b = vector->getY();
			if(a<0){ 
				a *= -1;
			}if (b < 0) {
				b *= -1;
			}
			float length = sqrt((a*a)+(b*b));
			float scalar = current->getSpeed() / length;
			vector->scalar(scalar);
			vector->scalar(this->timer->getElapsed());
			current->move(vector);
			}
			mob = mob->getNext();
	}
}
