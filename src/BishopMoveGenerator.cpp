#ifndef BishopMoveGenerator_cpp
#define BishopMoveGenerator_cpp
	#include "BishopMoveGenerator.h"

	BishopMoveGenerator::BishopMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: SlideMoveGenerator(board, moveStack) {
	}

	BishopMoveGenerator::~BishopMoveGenerator() {
	}
#endif