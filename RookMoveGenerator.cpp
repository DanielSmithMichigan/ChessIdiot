#ifndef RookMoveGenerator_cpp
#define RookMoveGenerator_cpp
	#include "RookMoveGenerator.h"

	RookMoveGenerator::RookMoveGenerator() {
		canMoveEast = true;
		canMoveNorth = true;
		canMoveWest = true;
		canMoveSouth = true;
		generatePotentialMoveSets();
	}

	RookMoveGenerator::~RookMoveGenerator() {
	}
#endif