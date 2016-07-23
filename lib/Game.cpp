#ifndef Game_cpp
#define Game_cpp
	#include "Game.h"

	Game::Game(shared_ptr<Board> board) : board(move(board)) {
	}

	Game::~Game() {
	}
#endif