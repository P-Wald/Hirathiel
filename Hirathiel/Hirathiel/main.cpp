#include "Game.hpp"

int main(int argc, char **argv) {
	Game* game = new Game();
	if (game) {
		game->runApp();
	}
	return 0;
}