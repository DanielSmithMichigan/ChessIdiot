#ifndef RookMoveGenerator_cpp
#define RookMoveGenerator_cpp
	#include "RookMoveGenerator.h"

	RookMoveGenerator::RookMoveGenerator() {
		canSlideEast = true;
		canSlideNorth = true;
		canSlideWest = true;
		canSlideSouth = true;
		generatePotentialMoveSets();
	}

	RookMoveGenerator::~RookMoveGenerator() {
	}
#endif