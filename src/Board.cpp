#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		initializeEmptyBoard();
		initializeFirstMove();
		initializeEnPassant();
		movesPlayed.resize(MAX_MOVES_PLAYED);
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

	void Board::place(int piece, int to) {
		squares[to] = piece;
		if (piece == BLACK_KING) {
			blackKingLocation = to;
		} 
		if (piece == WHITE_KING) {
			whiteKingLocation = to;
		}
	}

	void Board::remove(int location) {
		squares[location] = EMPTY_SPACE;
	}

	void Board::undoMove() {
		uint32_t move = movesPlayed.back();
		movesPlayed.pop_back();
		changeTurn();
		int from = FROM(move);
		int to = TO(move);
		firstMove[from] = FIRST_MOVE(move);
		squares[from] = squares[to];
		squares[to] = CAPTURED_PIECE(move);
	}

	void Board::doMove(uint32_t move) {
		changeTurn();
		int from = FROM(move);
		int to = TO(move);
		place(squares[from], to);
		remove(from);
		firstMove[to] = 0;
		movesPlayed.push_back(move);
	}

	void Board::changeTurn() {
		turn = GET_OPPOSING_COLOR(turn);
	}
#endif