#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	State* Board::currentState = new State();
	uint8_t Board::turn = 0;
	uint64_t Board::occupiedSquares = 0;
	uint64_t Board::colors[2] = {};
	uint64_t Board::pieces[8] = {};
	uint8_t Board::piecesIndex[64] = {};
	uint8_t Board::colorsIndex[64] = {};

	Board::Board() {
	}

	Board::~Board() {
	}

	void Board::doMove(uint32_t move) {
		uint8_t from = FROM(move);
		uint8_t to = TO(move);
		uint8_t piece = piecesIndex[from];
		uint8_t color = colorsIndex[from];

		put(color, piece, to);
		remove(color, piece, from);

		State* nextState = new State();
		nextState->move = move;
		nextState->prev = currentState;
		currentState = nextState;
	}

	void Board::undoMove() {
		uint32_t move = currentState->move;
		uint8_t from = FROM(move);
		uint8_t to = TO(move);
		uint8_t piece = piecesIndex[to];
		uint8_t color = colorsIndex[to];

		put(color, piece, from);
		remove(color, piece, to);
		State *prevState = currentState->prev;
		delete currentState;
		currentState = prevState;
	}

	void Board::reset() {

	}

	void Board::put(bool color, uint8_t piece, uint8_t location) {
		uint64_t pieceBoard = 0x8000000000000000 >> location;
		occupiedSquares |= pieceBoard;
		colors[color] |= pieceBoard;
		pieces[piece] |= pieceBoard;
		piecesIndex[location] = piece;
		colorsIndex[location] = color;
	}

	void Board::remove(bool color, uint8_t piece, uint8_t location) {
		uint64_t pieceBoard = 0x8000000000000000 >> location;
		pieceBoard = ~pieceBoard;
		occupiedSquares &= pieceBoard;
		colors[color] &= pieceBoard;
		pieces[piece] &= pieceBoard;
		piecesIndex[location] = EMPTY_SPACE;
		colorsIndex[location] = BLANK;
	}
#endif