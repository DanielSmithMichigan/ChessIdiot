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
		int potentialKnightMoves[] = {-2, -1, 1, 2};
		int potentialKnightMovesSize = (sizeof(potentialKnightMoves)/sizeof(*potentialKnightMoves));
		uint64_t moveSet = 0;
		for (int i = 0; i < potentialKnightMovesSize; i++) {
			int addToX = potentialKnightMoves[i];
			int testX = x + addToX;
			for (int j = 0; j < potentialKnightMovesSize; j++) {
				int addToY = potentialKnightMoves[j];
				int testY = y + addToY;
				if (isValidKnightMove(addToX, addToY)
					&& onBoard(testX, testY)) {
					moveSet |= identityBoardFromXy(testX, testY);
				}
			}
		}
		return moveSet;
	}

	bool KnightMoveGenerator::isValidKnightMove(int x, int y) {
		return abs(x) != abs(y);
	}

	bool KnightMoveGenerator::onBoard(int x, int y) {
		return x < BOARD_WIDTH 
				&& x >= 0
				&& y < BOARD_WIDTH
				&& y >= 0;
	}
#endif