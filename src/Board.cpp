#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		initializeEmptyBoard();
		initializeFirstMove();
		initializeEnPassant();
	}

	Board::~Board() {
	}

	void Board::initializePieces() {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			place(WHITE_PAWN, x + ROWS(1));
			place(BLACK_PAWN, x + ROWS(5));
		}
		place(BLACK_ROOK, 7);
		place(BLACK_ROOK, 0);
		place(BLACK_KNIGHT, 6);
		place(BLACK_KNIGHT, 1);
		place(BLACK_BISHOP, 5);
		place(BLACK_BISHOP, 2);
		place(BLACK_QUEEN, 3);
		place(BLACK_KING, 4);
		place(WHITE_ROOK, ROWS(7));
		place(WHITE_ROOK, ROWS(7) + 7);
		place(WHITE_KNIGHT, ROWS(7) + 6);
		place(WHITE_KNIGHT, ROWS(7) + 6);
		place(WHITE_BISHOP, ROWS(7) + 5);
		place(WHITE_BISHOP, ROWS(7) + 2);
		place(WHITE_QUEEN, ROWS(7) + 3);
		place(WHITE_KING, ROWS(7) + 4);
	}

	void Board::initializeEmptyBoard() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			squares[i] = EMPTY_SPACE;
		}
	}

	void Board::initializeFirstMove() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			firstMove[i] = true;
		}
	}

	void Board::initializeEnPassant() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			enPassant[i] = false;
		}
	}

	void Board::place(int piece, int location) {
		squares[location] = piece;
	}
#endif