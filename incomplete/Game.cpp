#ifndef Game_cpp
#define Game_cpp
	#include "Game.h"

	Game::Game(shared_ptr<Board> board, shared_ptr<SelectedSquare> selectedSquare, shared_ptr<TerminalDisplay> terminalDisplay) 
	: board(move(board)),
	terminalDisplay(move(terminalDisplay)),
	selectedSquare(move(selectedSquare)) {
	}

	Game::~Game() {
	}

	void Game::begin() {
		selectedSquare->get();
		getch();
		selectedSquare->get();
		getch();
		selectedSquare->get();
		getch();
		selectedSquare->get();
		getch();
		selectedSquare->get();
		getch();
		selectedSquare->get();
		getch();

	}
#endif