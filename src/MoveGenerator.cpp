#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	//FULL_MOVE(from,to,captured,enPassant,firstMove,promotedPiece,castle)

	MoveGenerator::MoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) :
		board(board),
		moveStack(moveStack),
		attackedSquare(attackedSquare) {
	}

	MoveGenerator::~MoveGenerator() {

	}

	void MoveGenerator::generateMove(int from, int to, int promotedPiece, int enPassant, int castle) {
		uint32_t move = MOVE(from, to, board->squares[to], enPassant, board->firstMove[from], promotedPiece, castle);
		if (isLegal(move)) {
			moveStack->push(move);
		}
	}

	bool MoveGenerator::isLegal(uint32_t move) {
		bool legal = true;
		board->doMove(move);
		legal = legal && !attackedSquare->kingInCheck(GET_OPPOSING_COLOR(board->turn));
		board->undoMove();
		return legal;
	}
#endif