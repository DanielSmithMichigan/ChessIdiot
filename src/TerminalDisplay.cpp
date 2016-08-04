#ifndef TerminalDisplay_cpp
#define TerminalDisplay_cpp
	#include "TerminalDisplay.h"

	const int CURSES_COLORS[] = {
		COLOR_BLACK,
        COLOR_RED,
        COLOR_GREEN,
        COLOR_YELLOW,
        COLOR_BLUE,
        COLOR_MAGENTA,
        COLOR_CYAN,
        COLOR_WHITE
    };

	TerminalDisplay::TerminalDisplay(shared_ptr<Board> board) 
		: board(move(board)) {
		initscr();
		raw();
		noecho();
		start_color();
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				colors[i][j] = i * 8 + j + 1;
				init_pair(colors[i][j], CURSES_COLORS[i], CURSES_COLORS[j]);
			}
		}
	}

	TerminalDisplay::~TerminalDisplay() {
		endwin();
	}

	void TerminalDisplay::draw() {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				drawSquare(x, y);
			}
		}
		drawMargin();
		refresh();
		getch();
	}

	void TerminalDisplay::drawSquare(int x, int y) {
		for (int column = 0; column < SQUARE_WIDTH; column++) {
			for (int row = 0; row < SQUARE_HEIGHT; row++) {
				move(row + getSquareYOffset(x, y) + 1, column + getSquareXOffset(x, y) + 1);
				write(getCharacterForLocation(column, row, x, y), getForegroundColorForLocation(x, y), getBackgroundColorForLocation(x, y));
			}
		}
	}

	void TerminalDisplay::write(char character, int background, int foreground) {
		attron(COLOR_PAIR(colors[background][foreground]));
		addch(character);
		attroff(COLOR_PAIR(colors[background][foreground]));
	}

	void TerminalDisplay::drawMargin() {
		for (int x = 0; x < (2 * MARGIN_HORIZONTAL) + BOARD_SCREEN_WIDTH; x++) {
			for(int y = 0; y < MARGIN_VERTICAL; y++) {
				move(y + 1, x + 1);
				write(' ', COLOR_WHITE, COLOR_BLACK);
				move(y + 1 + BOARD_SCREEN_HEIGHT + MARGIN_VERTICAL, x + 1);
				write(' ', COLOR_WHITE, COLOR_BLACK);
			}
		}
		for (int x = 0; x < MARGIN_HORIZONTAL; x++) {
			for(int y = MARGIN_VERTICAL; y < MARGIN_VERTICAL + BOARD_SCREEN_HEIGHT; y++) {
				move(y + 1, x + 1);
				write(' ', COLOR_WHITE, COLOR_BLACK);
				move(y + 1, x + 1 + BOARD_SCREEN_WIDTH + MARGIN_HORIZONTAL);
				write(' ', COLOR_WHITE, COLOR_BLACK);
			}
		}
	}

	char TerminalDisplay::getCharacterForLocation(int row, int column, int x, int y) {
		if (column == SQUARE_CENTER_Y
			&& row == SQUARE_CENTER_X) {
			switch(board->squares[x][y]->piece) {
				case PAWN:
					return 'P';
				case ROOK:
					return 'R';
				case KNIGHT:
					return 'N';
				case BISHOP:
					return 'B';
				case QUEEN:
					return 'Q';
				case KING:
					return 'K';
			}
		}
		return ' ';
	}

	int TerminalDisplay::getForegroundColorForLocation(int x, int y) {
		if (board->squares[x][y]->piece == EMPTY_SPACE) {
			return COLOR_WHITE;
		}
		switch(board->squares[x][y]->color) {
			case WHITE:
				return COLOR_RED;
			case BLACK:
				return COLOR_BLUE;
		}
		throw("TerminalDisplay::getForegroundColorForLocation");
	}

	int TerminalDisplay::getBackgroundColorForLocation(int x, int y) {
		return board->squares[x][y]->backgroundColor == "WHITE" ? COLOR_WHITE : COLOR_BLACK;
	}

	int TerminalDisplay::getSquareXOffset(int x, int y) {
		return (x * SQUARE_WIDTH) + MARGIN_HORIZONTAL;
	}

	int TerminalDisplay::getSquareYOffset(int x, int y) {
		return (y * SQUARE_HEIGHT) + MARGIN_VERTICAL;
	}
#endif