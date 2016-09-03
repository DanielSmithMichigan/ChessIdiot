#ifndef BishopMoveGenerator_cpp
#define BishopMoveGenerator_cpp
	#include "BishopMoveGenerator.h"

	BishopMoveGenerator::BishopMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: SlideMoveGenerator(board, moveStack) {
		SlideMoveGenerator::canMoveNorthEast = true;
		SlideMoveGenerator::canMoveSouthEast = true;
		SlideMoveGenerator::canMoveNorthWest = true;
		SlideMoveGenerator::canMoveSouthWest = true;
	}

	BishopMoveGenerator::~BishopMoveGenerator() {
	}
#endif