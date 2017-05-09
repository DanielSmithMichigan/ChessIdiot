#include "BitBoard.h"

uint64_t BitBoard::RookOccupancyMasks[64] = {};
uint64_t BitBoard::BishopOccupancyMasks[64] = {};

void BitBoard::InitRookBitBoards() {
	uint64_t mask, up, down, left, right, occupancyMask, subset, slideMoves;
	for (int i = 0; i < BOARD_SIZE; i++) {
		up = generateSlideMove(0, i, 0, -1);
		right = generateSlideMove(0, i, 1, 0);
		down = generateSlideMove(0, i, 0, 1);
		left = generateSlideMove(0, i, -1, 0);
		occupancyMask = (up & ~row<0>())
					| (right & ~file<7>())
					| (down & ~row<7>())
					| (left & ~file<0>());
		RookOccupancyMasks[i] = occupancyMask;
		subset = 0;
		do {
			subset = (subset - occupancyMask) & occupancyMask;
			slideMoves = generateSlideMove(subset, i, 0, -1)
				| generateSlideMove(subset, i, 1, 0)
				| generateSlideMove(subset, i, 0, 1)
				| generateSlideMove(subset, i, -1, 0);
		} while (subset);
	}
}

void BitBoard::InitBishopBitBoards() {
	uint64_t mask, upLeft, upRight, downRight, downLeft, occupancyMask, subset, slideMoves;
	for (int i = 28; i < 29; i++) {
		upLeft = generateSlideMove(0, i, -1, -1);
		upRight = generateSlideMove(0, i, 1, -1);
		downRight = generateSlideMove(0, i, 1, 1);
		downLeft = generateSlideMove(0, i, -1, 1);
		occupancyMask = (upLeft & ~row<0>() & ~file<0>())
					| (upRight & ~row<0>() & ~file<7>())
					| (downRight & ~row<7>() & ~file<7>())
					| (downLeft & ~row<7>() & ~file<0>());
		BishopOccupancyMasks[i] = occupancyMask;
		subset = 0;
		do {
			subset = (subset - occupancyMask) & occupancyMask;
			slideMoves = generateSlideMove(subset, i, -1, -1)
				| generateSlideMove(subset, i, 1, -1)
				| generateSlideMove(subset, i, 1, 1)
				| generateSlideMove(subset, i, -1, 1);
		} while (subset);
	}
}