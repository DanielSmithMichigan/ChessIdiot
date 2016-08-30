#ifndef RookMoveGenerator_cpp
#define RookMoveGenerator_cpp
	#include "RookMoveGenerator.h"

	RookMoveGenerator::RookMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: SlideMoveGenerator(board, moveStack) {
	}

	RookMoveGenerator::~RookMoveGenerator() {
	}
#endif