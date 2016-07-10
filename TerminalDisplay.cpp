#ifndef TerminalDisplay_cpp
#define TerminalDisplay_cpp
	#include "TerminalDisplay.h"

	TerminalDisplay::TerminalDisplay(Screen *screenInput, shared_ptr<Board> board) 
		: board(move(board)) {
		screen.reset(screenInput);
	}

	TerminalDisplay::~TerminalDisplay() {
	}

	void TerminalDisplay::draw() {
		screen->clear();
		for (int i = 0; i < BOARD_SIZE; i++) {
			screen->gotoxy(board->squares[i]->row, board->squares[i]->column);
			screen->write(to_string(board->squares[i]->number), board->squares[i]->foregroundColor, board->squares[i]->backgroundColor);
		}
	}
#endif