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
				uint64_t moveSet = 0;
				cout << (float)moveSet << endl;
				if (canMoveNorth) {
					moveSet |= generateNorthMoves(x, y);
				}
				cout << (float)moveSet << endl;
				if (canMoveSouth) {
					moveSet |= generateSouthMoves(x, y);
				}
				cout << (float)moveSet << endl;
				if (canMoveEast) {
					moveSet |= generateEastMoves(x, y);
				}
				cout << (float)moveSet << endl;
				if (canMoveWest) {
					moveSet |= generateWestMoves(x, y);
				}
				cout << (float)moveSet << endl;
				potentialMoveSets[x][y] = moveSet;
			}
		}
	}

	uint64_t MoveGenerator::movesAt(int x, int y) {
		return potentialMoveSets[x][y];
	}

	uint64_t MoveGenerator::generateEastMoves(int x, int y) {
		uint64_t outputBoard = 0;
		while(++x < BOARD_WIDTH) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}

	uint64_t MoveGenerator::generateWestMoves(int x, int y) {
		uint64_t outputBoard = 0;
		while(--x >= 0) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}

	uint64_t MoveGenerator::generateNorthMoves(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}

	uint64_t MoveGenerator::generateSouthMoves(int x, int y) {
		uint64_t outputBoard = 0;
		while(++y < BOARD_WIDTH) {
			outputBoard |= (uint64_t)1 << xyToInt(x, y);
		}
		return outputBoard;
	}
#endif