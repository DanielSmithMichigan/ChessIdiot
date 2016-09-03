#ifndef QueenMoveGenerator_cpp
#define QueenMoveGenerator_cpp
	#include "QueenMoveGenerator.h"

	QueenMoveGenerator::QueenMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: SlideMoveGenerator(board, moveStack) {
		SlideMoveGenerator::canMoveEast = true;
		SlideMoveGenerator::canMoveNorthEast = true;
		SlideMoveGenerator::canMoveNorth = true;
		SlideMoveGenerator::canMoveNorthWest = true;
		SlideMoveGenerator::canMoveWest = true;
		SlideMoveGenerator::canMoveSouthWest = true;
		SlideMoveGenerator::canMoveSouth = true;
		SlideMoveGenerator::canMoveSouthEast = true;
	}

	QueenMoveGenerator::~QueenMoveGenerator() {
	}
#endif