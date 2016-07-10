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
			drawSquare(i);
		}
		drawMargin();
	}

	void TerminalDisplay::drawSquare(int squareNum) {
		int column = board->squares[squareNum]->column;
		int row = board->squares[squareNum]->row;
		for (int x = 0; x < SQUARE_WIDTH; x++) {
			for (int y = 0; y < SQUARE_HEIGHT; y++) {
				screen->gotoxy(x + getSquareXOffset(squareNum, column) + 1, y + getSquareYOffset(squareNum, row) + 1);
				screen->write(getCharacterForLocation(x, y, squareNum), getForegroundColorForLocation(x, y, squareNum), board->squares[squareNum]->backgroundColor);
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

	string TerminalDisplay::getCharacterForLocation(int x, int y, int squareNum) {
		if (x == SQUARE_CENTER_X
			&& y == SQUARE_CENTER_Y) {
			switch(board->squares[squareNum]->piece) {
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

	string TerminalDisplay::getForegroundColorForLocation(int x, int y, int squareNum) {
		if (board->squares[squareNum]->piece == EMPTY_SPACE) {
			return "WHITE";
		}
		switch(board->squares[squareNum]->color) {
			case WHITE:
				return "RED";
			case BLACK:
				return "BLUE";
		}
		throw "Unrecognized Color";
	}

	int TerminalDisplay::getSquareXOffset(int squareNum, int column) {
		return (column * SQUARE_WIDTH) + MARGIN_HORIZONTAL;
	}

	int TerminalDisplay::getSquareYOffset(int squareNum, int row) {
		return (row * SQUARE_HEIGHT) + MARGIN_VERTICAL;
	}
#endif