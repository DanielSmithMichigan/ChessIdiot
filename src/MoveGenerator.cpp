#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	MoveGenerator::MoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) :
		board(board),
		moveStack(moveStack),
		attackedSquare(attackedSquare) {
	}

	MoveGenerator::~MoveGenerator() {

	}

	void MoveGenerator::generateMove(int from, int to, int promotedPiece, bool enPassant, bool castle) {
		moveStack->push(MOVE(from, to, Board::squares[to], enPassant, promotedPiece, castle, board->blackCanCastleLeft, board->blackCanCastleRight, board->whiteCanCastleLeft, board->whiteCanCastleRight));
	}
#endif