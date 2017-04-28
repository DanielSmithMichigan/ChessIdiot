#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	State* Board::currentState = new State();
	uint32_t Board::turn = 0;
	uint64_t Board::occupiedSquares = 0;
	uint64_t Board::colors[2] = {};
	uint64_t Board::pieces[8] = {};
	uint32_t Board::piecesIndex[64] = {};
	uint32_t Board::colorsIndex[64] = {};

	Board::Board() {
	}

	Board::~Board() {
	}

	void Board::doMove(uint32_t move) {
		uint32_t from = FROM(move);
		uint32_t to = TO(move);
		uint32_t piece = piecesIndex[from];
		uint32_t color = colorsIndex[from];

		put(color, piece, to);
		remove(color, piece, from);

		State* nextState = new State();
		nextState->move = move;
		nextState->prev = currentState;
		currentState = nextState;
	}

	void Board::undoMove() {
		uint32_t move = currentState->move;
		uint32_t from = FROM(move);
		uint32_t to = TO(move);
		uint32_t piece = piecesIndex[to];
		uint32_t color = colorsIndex[to];

		put(color, piece, from);
		remove(color, piece, to);
		State *prevState = currentState->prev;
		delete currentState;
		currentState = prevState;
	}

	void Board::reset() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			piecesIndex[i] = 0;
			colorsIndex[i] = 0;
		}
		for (int i = 0; i < 2; i++) {
			colors[i] = 0;
		}
		for (int i = 0; i < 8; i++) {
			pieces[i] = 0;
		}
		occupiedSquares = 0;
	}

	void Board::put(bool color, uint32_t piece, uint32_t location) {
		uint64_t pieceBoard = getPieceBoard(location);
		occupiedSquares |= pieceBoard;
		colors[color] |= pieceBoard;
		pieces[piece] |= pieceBoard;
		piecesIndex[location] = piece;
		colorsIndex[location] = color;
	}

	void Board::remove(bool color, uint32_t piece, uint32_t location) {
		uint64_t pieceBoard = getPieceBoard(location);
		pieceBoard = ~pieceBoard;
		occupiedSquares &= pieceBoard;
		colors[color] &= pieceBoard;
		pieces[piece] &= pieceBoard;
		piecesIndex[location] = EMPTY_SPACE;
		colorsIndex[location] = BLANK;
	}
#endif