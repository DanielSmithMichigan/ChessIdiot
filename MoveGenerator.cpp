#ifndef MoveGenerator_cpp
#define MoveGenerator_cpp
	#include "MoveGenerator.h"

	MoveGenerator::MoveGenerator() {
	}

	MoveGenerator::~MoveGenerator() {

	}

	void MoveGenerator::generatePotentialMoveSets() {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				uint8_t moveSet = 0;
				if (canMoveNorth) {
					moveSet |= generateNorthMoves(x, y);
				}
				if (canMoveSouth) {
					moveSet |= generateSouthMoves(x, y);
				}
				if (canMoveEast) {
					moveSet |= generateEastMoves(x, y);
				}
				if (canMoveWest) {
					moveSet |= generateWestMoves(x, y);
				}
				potentialMoveSets[xyToInt(x, y)] = moveSet;
			}
		}
	}

	uint8_t MoveGenerator::generateEastMoves(int x, int y) {
		uint8_t outputBoard = 0;
		while(++x < BOARD_WIDTH) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}

	uint8_t MoveGenerator::generateWestMoves(int x, int y) {
		uint8_t outputBoard = 0;
		while(--x >= 0) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}

	uint8_t MoveGenerator::generateNorthMoves(int x, int y) {
		uint8_t outputBoard = 0;
		while(--y >= 0) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}

	uint8_t MoveGenerator::generateSouthMoves(int x, int y) {
		uint8_t outputBoard = 0;
		while(++y < BOARD_WIDTH) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}
#endif