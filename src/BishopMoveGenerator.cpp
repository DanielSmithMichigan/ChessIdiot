#ifndef BishopMoveGenerator_cpp
#define BishopMoveGenerator_cpp
	#include "BishopMoveGenerator.h"

	BishopMoveGenerator::BishopMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) 
		: SlideMoveGenerator(board, moveStack, attackedSquare) {
		SlideMoveGenerator::canMoveNorthEast = true;
		SlideMoveGenerator::canMoveSouthEast = true;
		SlideMoveGenerator::canMoveNorthWest = true;
		SlideMoveGenerator::canMoveSouthWest = true;
	}

	BishopMoveGenerator::~BishopMoveGenerator() {
	}
#endif