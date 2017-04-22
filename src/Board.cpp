#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
	}

	Board::~Board() {
	}

	void Board::doMove() {

	}

	void Board::put(bool color, uint8_t piece, uint8_t location) {
		uint64_t pieceBoard = 1 >> location;
		occupiedSquares |= pieceBoard;
		colors[color] |= pieceBoard;
		pieces[piece] |= pieceBoard;
		piecesIndex[location] = piece;
		colorsIndex[location] = color;
	}
#endif