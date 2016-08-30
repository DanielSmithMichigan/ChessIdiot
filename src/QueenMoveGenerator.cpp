#ifndef QueenMoveGenerator_cpp
#define QueenMoveGenerator_cpp
	#include "QueenMoveGenerator.h"

	QueenMoveGenerator::QueenMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: SlideMoveGenerator(board, moveStack) {
	}

	QueenMoveGenerator::~QueenMoveGenerator() {
	}
#endif