#ifndef SelectedSquare_cpp
#define SelectedSquare_cpp
	#include "SelectedSquare.h"

	SelectedSquare::SelectedSquare(shared_ptr<Board> board, shared_ptr<TerminalDisplay> terminalDisplay)
	: board(move(board)),
	  terminalDisplay(move(terminalDisplay)) {
	}

	SelectedSquare::~SelectedSquare() {
	}

	void SelectedSquare::get() {
		reset();
		display();
		while (!selected) {
			getInput();
			resetBoard();
	    	useInput();
	    	normalize();
	    	display();
    	}
	}

	void SelectedSquare::resetBoard() {
		board->removeIndicatorColors();
	}

	void SelectedSquare::display() {
		if (selected) {
			board->doForAllMatches(x, y, SELECT);
		} else {
			board->doForAllMatches(x, y, HIGHLIGHT);
		}
    	terminalDisplay->draw();
	}

	void SelectedSquare::getInput() {
		input = getch();
	}

	void SelectedSquare::useInput() {
		switch(input) {
			case 'w':
				y--;
			return;
			case 'a':
				x--;
			return;
			case 's':
				y++;
			return;
			case 'd':
				x++;
			return;
			case 'e':
				selected = true;
			return;
		}
	}

	void SelectedSquare::normalize() {
		x = max(x, 0);
		x = min(x, BOARD_WIDTH - 1);
		y = max(y, 0);
		y = min(y, BOARD_WIDTH - 1);
	}

	void SelectedSquare::reset() {
		x = 0;
		y = 0;
		selected = false;
		resetBoard();
	}
#endif