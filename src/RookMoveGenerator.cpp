#ifndef RookMoveGenerator_cpp
#define RookMoveGenerator_cpp
	#include "RookMoveGenerator.h"

	RookMoveGenerator::RookMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: SlideMoveGenerator(board, moveStack) {
		SlideMoveGenerator::canMoveEast = true;
		SlideMoveGenerator::canMoveNorth = true;
		SlideMoveGenerator::canMoveWest = true;
		SlideMoveGenerator::canMoveSouth = true;
	}

	RookMoveGenerator::~RookMoveGenerator() {
	}
#endif