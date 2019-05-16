#include "Game.hpp"
#include <stdlib.h> 
#include <chrono>
#include "Cripple.hpp"
#include <mutex>
#include <vector>

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
	this->cd = 0;
	game = this;
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
	this->items = new ItemList(this->renderer, this->textures);

	this->actions = new CombatActionList();
	this->mobs = new MobList(this->items);
	this->player = new Player(640, 360, 100, 100, this->renderer, this->textures->getPlayer(),this->items);
	this->player->setRes(this->res);
	player = this->player;
	this->mobs->add(this->player);

	this->timer = new CTimer();
	moblist = this->mobs;
	this->actions->setMobs(this->mobs);
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


	vector<MoB> vectors;
	Text score(this->renderer, "res/PARCHM.TTF", 100, {0,0,0,0});
	Text text(this->renderer,"res/PARCHM.TTF", 100, { 0,0,0,0 });
	srand(chrono::system_clock::now().time_since_epoch().count());
	this->timer->update();
	int i = 0;
	time_t start = time(NULL);
	bool spawned = false;
	this->player->setLife(200, 200);

	std::string str = "Score:";
	text.setText(str);

	while (this->window->getrun()) {
		if (this->player->getLife() <= 0) {
			/*std::cout << "Player died" << std::endl;
			break;*/
			//enable this line for debug purposes only
			this->player->setLife(this->player->getLifeMax(), this->player->getLifeMax());
		}
		if (time(NULL) - start >= 1) {
			start = time(NULL);
			std::cout << i << std::endl;
			i = 0;
		}
		text.display(20, 0);
		std::string message = std::to_string(this->mobs->getScore());
		score.setText(message);
		score.display(175,0);


		this->timer->update();

		
		/*Prints out Time needed per Lap/per Frame
		std::cout << this->timer->getElapsed() << std::endl;*/


		//comment out to remove mob spawn
		if (!spawned){
			this->spawn();
			spawned = true;
		}if (this->mobs->getSize()<=1) {
			spawned = false;
		}




		const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
		this->pollEvents(currentKeyStates);
		this->mobs->draw();
		this->items->draw();

		this->actions->poll();

		this->window->clear(this->textures->getGrassland());

		//Comment out to disable Mobscript
		this->aiThread(this->timer);
		this->mobs->triggerEffects(MoBLock);

		i++;
	}
	//For debugging
	//std::cout << "Game Ended" << std::endl;
	//std::cin >> i;
}

void Game::spawn() {
	for (int i = 0; i <= 10; i++) {
		MoB* mob = new MoB(i * 120, 100, 100, 100, this->renderer, this->textures->getOrc());
		mob->setRes(this->res);
		this->mobs->add(mob);
		mob = nullptr;
		delete mob;
	}	
}



//Script that calculates a vector based on own and player position to move the enemies to
//Script will stop moving if an enemy is close to the player and place an attack towards that
void Game::aiThread(CTimer* aiTimer){
	MoB* current = nullptr;
	this->cd -= this->timer->getElapsed();
	auto list = this->mobs->get();

	for (int i = 1; i < list.size(); i++) {
		current =list.at(i);
		if (current) {
			Vector2D* vector = new Vector2D(this->player->getX() - current->getX(), this->player->getY() - current->getY());
			int a, b; a = vector->getX(); b = vector->getY();
			if (a < 0) {
				a *= -1;
			}if (b < 0) {
				b *= -1;
			}
			float length = sqrt((a * a) + (b * b));
			float scalar = current->getSpeed() / length;
			vector->scalar(scalar);
			vector->scalar(this->timer->getElapsed());
			if (length > 100) {
				current->move(vector);
			}
			else {
				delete vector;
				if (this->cd <= 0) {
					MoBMetaData data = MoBMetaData(current->getX() + current->getW() / 2, current->getY() + current->getH() / 2, current->getW(), current->getH(), 10, 1.5);
					SDL_Rect* rect = new SDL_Rect();
					rect->x = this->player->getX(); rect->y = this->player->getY();
					rect->w = 50; rect->h = 50;
					Strike* combat = new Strike(data, rect, nullptr, this->renderer, current->getX(), current->getY());
					combat->settarget(this->player->getX(), this->player->getY());
					combat->setFaction(0);
					//Needs cooldown;
					this->actions->add(combat);
					rect = nullptr; combat = nullptr;
					delete rect; delete combat;
					this->cd = 0.3;
				}
			}
		}

	}
	current = nullptr;
	delete current;
}
