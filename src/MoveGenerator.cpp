#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	//FULL_MOVE(from,to,captured,enPassant,firstMove,promotedPiece,castle)

	MoveGenerator::MoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) :
	board(move(board)),	moveStack(move(moveStack)) {
	}

	MoveGenerator::~MoveGenerator() {

	}

	void MoveGenerator::generateMoves(int location) {

	}

	void MoveGenerator::generateSlideMove(int from, int delta) {
		int to = from;
		while (ON_BOARD(to += delta)) {
			if (board->squares != EMPTY_SPACE) {
				if (GET_COLOR(board->squares[to]) != GET_COLOR(board->squares[from])) {
					generateMove(from, to);
				}
				break;
			}
			generateMove(from, to);
		}
	}

	void MoveGenerator::generateMove(int from, int to) {
		moveStack->push(MOVE(from, to, board->squares[to], BLANK, board->firstMove[from], BLANK, BLANK));
	}
#endif