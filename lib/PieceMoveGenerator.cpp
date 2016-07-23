#ifndef PieceMoveGenerator_cpp
#define PieceMoveGenerator_cpp
	#include "PieceMoveGenerator.h"

	PieceMoveGenerator::PieceMoveGenerator() {
	}

	PieceMoveGenerator::~PieceMoveGenerator() {

	}

	void PieceMoveGenerator::generatePotentialMoveSets() {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				uint64_t moveSet = 0;
				if (canSlideNorth) {
					moveSet |= generateNorthSlide(x, y);
				}
				if (canSlideNorthWest) {
					moveSet |= generateNorthWestSlide(x, y);
				}
				if (canSlideWest) {
					moveSet |= generateWestSlide(x, y);
				}
				if (canSlideSouthWest) {
					moveSet |= generateSouthWestSlide(x, y);
				}
				if (canSlideSouth) {
					moveSet |= generateSouthSlide(x, y);
				}
				if (canSlideSouthEast) {
					moveSet |= generateSouthEastSlide(x, y);
				}
				if (canSlideEast) {
					moveSet |= generateEastSlide(x, y);
				}
				if (canSlideNorthEast) {
					moveSet |= generateNorthEastSlide(x, y);
				}
				potentialMoveSets[x][y] = moveSet;
			}
		}
	}

	uint64_t PieceMoveGenerator::movesAt(int x, int y) {
		return potentialMoveSets[x][y];
	}

	uint64_t PieceMoveGenerator::generateEastSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(++x < BOARD_WIDTH) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateNorthEastSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0 && ++x < BOARD_WIDTH) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateNorthSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateNorthWestSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0 && --x >= 0) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateWestSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--x >= 0) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateSouthWestSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--x >= 0 && ++y < BOARD_WIDTH) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateSouthSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(++y < BOARD_WIDTH) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateSouthEastSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(++y < BOARD_WIDTH && ++x < BOARD_WIDTH) {
			outputBoard |= boardFromXy(x, y);
		}
		return outputBoard;
	}
#endif