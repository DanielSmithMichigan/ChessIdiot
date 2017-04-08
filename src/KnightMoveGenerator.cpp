#ifndef KnightMoveGenerator_cpp
#define KnightMoveGenerator_cpp
	#include "KnightMoveGenerator.h"

	KnightMoveGenerator::KnightMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) 
		: MoveGenerator(board, moveStack, attackedSquare) {
	}

	KnightMoveGenerator::~KnightMoveGenerator() {
	}

	void KnightMoveGenerator::generateMoves(int from) {
		for (int i = 0; i < KNIGHT_MOVES_SIZE; i++) {
			int to = knightMoves[i] + from;
			int pieceAtLocation = board->squares[to];
			if (ON_BOARD(to)
				&& (pieceAtLocation == EMPTY_SPACE
					|| GET_COLOR(board->getLocation(from)) != GET_COLOR(pieceAtLocation))) {
				generateMove(from, to);
			}
		}
	}
#endif