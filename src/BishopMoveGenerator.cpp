#ifndef BishopMoveGenerator_cpp
#define BishopMoveGenerator_cpp
	#include "BishopMoveGenerator.h"

	BishopMoveGenerator::BishopMoveGenerator() {
		canSlideNorthEast = true;
		canSlideNorthWest = true;
		canSlideSouthWest = true;
		canSlideSouthEast = true;
		generatePotentialMoveSets();
	}

	BishopMoveGenerator::~BishopMoveGenerator() {
	}
#endif