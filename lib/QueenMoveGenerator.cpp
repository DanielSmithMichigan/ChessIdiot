#ifndef QueenMoveGenerator_cpp
#define QueenMoveGenerator_cpp
	#include "QueenMoveGenerator.h"

	QueenMoveGenerator::QueenMoveGenerator() {
		canSlideEast = true;
		canSlideNorthEast = true;
		canSlideNorth = true;
		canSlideNorthWest = true;
		canSlideWest = true;
		canSlideSouthWest = true;
		canSlideSouth = true;
		canSlideSouthEast = true;
		generatePotentialMoveSets();
	}

	QueenMoveGenerator::~QueenMoveGenerator() {
	}
#endif