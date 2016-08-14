#ifndef KnightMoveGenerator_cpp
#define KnightMoveGenerator_cpp
	#include "KnightMoveGenerator.h"

	KnightMoveGenerator::KnightMoveGenerator() {
		generatePotentialMoveSets();
	}

	KnightMoveGenerator::~KnightMoveGenerator() {
	}

	void KnightMoveGenerator::generatePotentialMoveSets() {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				uint64_t moveSet = 0;
				moveSet |= generateKnightMovesAtLocation(x, y);
				potentialMoveSets[x][y] = moveSet;
			}
		}
	}

	uint64_t KnightMoveGenerator::generateKnightMovesAtLocation(int x, int y) {
	}
#endif