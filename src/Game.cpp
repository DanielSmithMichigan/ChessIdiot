#ifndef Game_cpp
#define Game_cpp
	#include "Game.h"

	Game::Game(shared_ptr<Board> board, UserCommand *userCommandInput) 
	: board(move(board)) {
	  	userCommand.reset(userCommandInput);
	}

	Game::~Game() {
	}
#endif