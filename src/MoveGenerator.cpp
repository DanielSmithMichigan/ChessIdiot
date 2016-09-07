#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	//FULL_MOVE(from,to,captured,enPassant,firstMove,promotedPiece,castle)

	MoveGenerator::MoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) :
		board(board),
		moveStack(moveStack) {
	}

	MoveGenerator::~MoveGenerator() {

	}

	void MoveGenerator::generateMove(int from, int to, int promotedPiece) {
		moveStack->push(MOVE(from, to, board->squares[to], BLANK, board->firstMove[from], promotedPiece, BLANK));
	}
#endif