#ifndef TerminalDisplay_cpp
#define TerminalDisplay_cpp
	#include "TerminalDisplay.h"

	TerminalDisplay::TerminalDisplay(Screen *screenInput, shared_ptr<Board> board, shared_ptr<UserSession> userSession) 
		: board(move(board)),
		  userSession(move(userSession)) {
		screen.reset(screenInput);
	}

	TerminalDisplay::~TerminalDisplay() {
	}

	void TerminalDisplay::begin() {
		while(true) {
			// draw();
			userSession->waitForInput();
		}
	}

	void TerminalDisplay::draw() {
		screen->clear();
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				drawSquare(x, y);
			}
		}
		drawMargin();
	}

	void TerminalDisplay::drawSquare(int x, int y) {
		for (int column = 0; column < SQUARE_WIDTH; column++) {
			for (int row = 0; row < SQUARE_HEIGHT; row++) {
				screen->gotoxy(column + getSquareXOffset(x, y) + 1, row + getSquareYOffset(x, y) + 1);
				screen->write(getCharacterForLocation(column, row, x, y), getForegroundColorForLocation(x, y), getBackgroundColorForLocation(x, y));
			}
		}
	}

	void TerminalDisplay::drawMargin() {
		for (int x = 0; x < (2 * MARGIN_HORIZONTAL) + BOARD_SCREEN_WIDTH; x++) {
			for(int y = 0; y < MARGIN_VERTICAL; y++) {
				screen->gotoxy(x + 1, y + 1);
				screen->write(" ", "WHITE", "BLACK");
				screen->gotoxy(x + 1, y + 1 + BOARD_SCREEN_HEIGHT + MARGIN_VERTICAL);
				screen->write(" ", "WHITE", "BLACK");
			}
		}
		for (int x = 0; x < MARGIN_HORIZONTAL; x++) {
			for(int y = MARGIN_VERTICAL; y < MARGIN_VERTICAL + BOARD_SCREEN_HEIGHT; y++) {
				screen->gotoxy(x + 1, y + 1);
				screen->write(" ", "WHITE", "BLACK");
				screen->gotoxy(x + 1 + BOARD_SCREEN_WIDTH + MARGIN_HORIZONTAL, y + 1);
				screen->write(" ", "WHITE", "BLACK");
			}
		}
	}

	string TerminalDisplay::getCharacterForLocation(int row, int column, int x, int y) {
		if (column == SQUARE_CENTER_Y
			&& row == SQUARE_CENTER_X) {
			switch(board->squares[x][y]->piece) {
				case PAWN:
					return "P";
				case ROOK:
					return "R";
				case KNIGHT:
					return "N";
				case BISHOP:
					return "B";
				case QUEEN:
					return "Q";
				case KING:
					return "K";
			}
		}
		return " ";
	}

	string TerminalDisplay::getForegroundColorForLocation(int x, int y) {
		if (board->squares[x][y]->piece == EMPTY_SPACE) {
			return "WHITE";
		}
		switch(board->squares[x][y]->color) {
			case WHITE:
				return "RED";
			case BLACK:
				return "BLUE";
		}
		throw "Unrecognized Color";
	}

	string TerminalDisplay::getBackgroundColorForLocation(int x, int y) {
		return board->squares[x][y]->backgroundColor;
	}

	int TerminalDisplay::getSquareXOffset(int x, int y) {
		return (x * SQUARE_WIDTH) + MARGIN_HORIZONTAL;
	}

	int TerminalDisplay::getSquareYOffset(int x, int y) {
		return (y * SQUARE_HEIGHT) + MARGIN_VERTICAL;
	}
#endif