#ifndef PieceMoveGenerator_cpp
#define PieceMoveGenerator_cpp
	#include "PieceMoveGenerator.h"

	PieceMoveGenerator::PieceMoveGenerator() {
		generate();
	}

	PieceMoveGenerator::~PieceMoveGenerator() {

	}

	void PieceMoveGenerator::generate() {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				moveBoards[x][y][NORTH] = generateNorthSlide(x, y);
				moveBoards[x][y][NORTHEAST] = generateNorthEastSlide(x, y);
				moveBoards[x][y][EAST] = generateEastSlide(x, y);
				moveBoards[x][y][SOUTHEAST] = generateSouthEastSlide(x, y);
				moveBoards[x][y][SOUTH] = generateSouthSlide(x, y);
				moveBoards[x][y][SOUTHWEST] = generateSouthWestSlide(x, y);
				moveBoards[x][y][WEST] = generateWestSlide(x, y);
				moveBoards[x][y][NORTHWEST] = generateNorthWestSlide(x, y);
				moveBoards[x][y][KNIGHT] = generateKnightMoves(x, y);
				moveBoards[x][y][PAWNATTACKWHITE] = generatePawnAttackMoves(x, y, WHITE);
				moveBoards[x][y][PAWNATTACKBLACK] = generatePawnAttackMoves(x, y, BLACK);
				moveBoards[x][y][PAWNFORWARDWHITE] = generatePawnForwardMoves(x, y, WHITE);
				moveBoards[x][y][PAWNFORWARDBLACK] = generatePawnForwardMoves(x, y, BLACK);
			}
		}
	}

	uint64_t PieceMoveGenerator::movesAt(int x, int y) {
		return moveBoards[x][y];
	}

	uint64_t PieceMoveGenerator::generateEastSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(++x < BOARD_WIDTH) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateNorthEastSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0 && ++x < BOARD_WIDTH) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateNorthSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateNorthWestSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--y >= 0 && --x >= 0) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateWestSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--x >= 0) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateSouthWestSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(--x >= 0 && ++y < BOARD_WIDTH) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateSouthSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(++y < BOARD_WIDTH) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateSouthEastSlide(int x, int y) {
		uint64_t outputBoard = 0;
		while(++y < BOARD_WIDTH && ++x < BOARD_WIDTH) {
			outputBoard |= identityBoardFromXy(x, y);
		}
		return outputBoard;
	}

	uint64_t PieceMoveGenerator::generateKnightMoves(int x, int y) {
		int potentialKnightMoves[] = {-2, -1, 1, 2};
		int potentialKnightMovesSize = (sizeof(potentialKnightMoves)/sizeof(*potentialKnightMoves));
		uint64_t moveSet = 0;
		for (int i = 0; i < potentialKnightMovesSize; i++) {
			int xModifier = potentialKnightMoves[i];
			int potentialX = x + xModifier;
			for (int j = 0; j < potentialKnightMovesSize; j++) {
				int yModifier = potentialKnightMoves[j];
				int potentialY = y + yModifier;
				if (isValidKnightMove(xModifier, yModifier)
					&& onBoard(potentialX, potentialY)) {
					moveSet |= identityBoardFromXy(potentialX, potentialY);
				}
			}
		}
		return moveSet;
	}

	uint64_t PieceMoveGenerator::generatePawnAttackMoves(int x, int y, int color) {
		int yModifier = -1;
		if (color == BLACK) {
			yModifier = 1;
		}
		uint64_t moveSet = 0;
		int potentialPawnAttackMoves[] = {-1, 1};
		int potentialPawnAttackMovesSize = (sizeof(potentialPawnAttackMoves)/sizeof(*potentialPawnAttackMoves));
		for (int i = 0; i < potentialPawnAttackMovesSize; i++) {
			int xModifier = potentialPawnAttackMoves[i];
			int potentialX = x + xModifier;
			int potentialY = y + yModifier;
			if (onBoard(potentialX, potentialY)) {
				moveSet |= identityBoardFromXy(potentialX, potentialY);
			}
		}
		return moveSet;
	}

	uint64_t PieceMoveGenerator::generatePawnForwardMoves(int x, int y, int color) {
		int yModifier = -1;
		if (color == BLACK) {
			yModifier = 1;
		}
		return identityBoardFromXy(x, y + yModifier);
	}

	bool PieceMoveGenerator::isValidKnightMove(int x, int y) {
		return abs(x) != abs(y);
	}

	bool PieceMoveGenerator::onBoard(int x, int y) {
		return x < BOARD_WIDTH 
				&& x >= 0
				&& y < BOARD_WIDTH
				&& y >= 0;
	}
#endif