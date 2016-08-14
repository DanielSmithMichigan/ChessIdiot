#ifndef KnightMoveGenerator_cpp
#define KnightMoveGenerator_cpp
	#include "KnightMoveGenerator.h"

	KnightMoveGenerator::KnightMoveGenerator(shared_ptr<Board> board) : PieceMoveGenerator(board) {
	}

	KnightMoveGenerator::~KnightMoveGenerator() {
	}

	uint64_t KnightMoveGenerator::movesAt(int x, int y, uint64_t color) {
		uint64_t knightMoves = moveBoards[x][y][KNIGHT];
		knightMoves &= ~board->colorBoards[color];
		return knightMoves;
	}
#endif