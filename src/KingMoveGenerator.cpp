#ifndef KingMoveGenerator_cpp
#define KingMoveGenerator_cpp
	#include "KingMoveGenerator.h"

	KingMoveGenerator::KingMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) 
		: MoveGenerator(board, moveStack, attackedSquare) {
	}

	KingMoveGenerator::~KingMoveGenerator() {
	}

	void KingMoveGenerator::generateMoves(int from) {
		for (int i = 0; i < KING_MOVES_SIZE; i++) {
			int to = kingMoves[i] + from;
			if (ON_BOARD(to) 
				&& (board->squares[to] == EMPTY_SPACE
					|| GET_COLOR(board->squares[from]) != GET_COLOR(board->squares[to]))) {
				generateMove(from, to);
			}
		}
	}
#endif