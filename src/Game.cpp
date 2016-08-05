#ifndef Game_cpp
#define Game_cpp
	#include "Game.h"

	Game::Game(shared_ptr<Board> board, UserCommand *userCommandInput, shared_ptr<TerminalDisplay> terminalDisplay) 
	: board(move(board)),
	terminalDisplay(move(terminalDisplay)) {
	  	userCommand.reset(userCommandInput);
	}

	Game::~Game() {
	}

	void Game::begin() {
		terminalDisplay->draw();
		userCommand->get();

	}
#endif