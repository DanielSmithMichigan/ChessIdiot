#ifndef MoveCache_cpp
#define MoveCache_cpp
	#include "MoveCache.h"

	MoveCache::MoveCache() {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				for (int move_type = 0; move_type < MOVE_TYPES; move_type++) {
					moveBoards[x][y][move_type] = 0;
					for (int i = 0; i < MOVE_LENGTH; i++) {
						moves[x][y][move_type][i] = 0;
					}
				}
			}
		}
		generate();
	}

	MoveCache::~MoveCache() {

	}

	void MoveCache::generate() {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				generateLists(x, y);
				generateBoards(x, y);
			}
		}
	}

	void MoveCache::generateLists(int x, int y) {
		generateSlideList(x, y, NORTH, NO_DIRECTION, NORTH);
		generateSlideList(x, y, NORTH, EAST, NORTHEAST);
		generateSlideList(x, y, NO_DIRECTION, EAST, EAST);
		generateSlideList(x, y, SOUTH, EAST, SOUTHEAST);
		generateSlideList(x, y, SOUTH, NO_DIRECTION, SOUTH);
		generateSlideList(x, y, SOUTH, WEST, SOUTHWEST);
		generateSlideList(x, y, NO_DIRECTION, WEST, WEST);
		generateSlideList(x, y, NORTH, WEST, NORTHWEST);
		generateKnightList(x, y);
		generatePawnAttackList(x, y, WHITE);
		generatePawnAttackList(x, y, BLACK);
		generatePawnForwardList(x, y, WHITE);
		generatePawnForwardList(x, y, BLACK);
	}

	void MoveCache::generateBoards(int x, int y) {
		for (int i = 0; i < MOVE_TYPES; i++) {
			moveBoards[x][y][i] = generateBoardFromList(x, y, i);
		}
	}

	uint64_t MoveCache::generateBoardFromList(int x, int y, int moveType) {
		uint64_t moveBoard;
		for (int i = 0; i < MOVE_LENGTH; i++) {
		    moveBoard |= identityBoardFromMove(moves[x][y][moveType][i]);
		}
		return moveBoard;
	}

	void MoveCache::generateSlideList(int x, int y, int eastWest, int northSouth, int moveListIndex) {
		int xModifier = getXModifier(eastWest);
		int yModifier = getYModifier(northSouth);
		int newX = x + xModifier;
		int newY = y + yModifier;
		int i;
		while (onBoard(newX, newY)) {
			moves[x][y][moveListIndex][i++] = MOVE(x,y,newX,newY);
			newX += xModifier;
			newY += yModifier;
		}
	}

	void MoveCache::generateKnightList(int x, int y) {
		int potentialKnightMoves[] = {-2, -1, 1, 2};
		int potentialKnightMovesSize = (sizeof(potentialKnightMoves)/sizeof(*potentialKnightMoves));
		int knightMoveIndex = 0;
		for (int i = 0; i < potentialKnightMovesSize; i++) {
			int xModifier = potentialKnightMoves[i];
			int potentialX = x + xModifier;
			for (int j = 0; j < potentialKnightMovesSize; j++) {
				int yModifier = potentialKnightMoves[j];
				int potentialY = y + yModifier;
				if (isValidKnightMove(xModifier, yModifier)
					&& onBoard(potentialX, potentialY)) {
					moves[x][y][KNIGHTMOVES][knightMoveIndex++] = MOVE(x, y, potentialX, potentialY);
				}
			}
		}
	}

	void MoveCache::generatePawnAttackList(int x, int y, int color) {
		int yModifier = -1;
		if (color == BLACK) {
			yModifier = 1;
		}
		int potentialPawnAttackMoves[] = {-1, 1};
		int potentialPawnAttackMovesSize = (sizeof(potentialPawnAttackMoves)/sizeof(*potentialPawnAttackMoves));
		int moveIndex = 0;
		for (int i = 0; i < potentialPawnAttackMovesSize; i++) {
			int xModifier = potentialPawnAttackMoves[i];
			int potentialX = x + xModifier;
			int potentialY = y + yModifier;
			if (onBoard(potentialX, potentialY)) {
				moves[x][y][color == WHITE ? PAWNATTACKWHITE : PAWNATTACKBLACK][moveIndex++] = MOVE(x, y, potentialX, potentialY);
			}
		}
	}

	void MoveCache::generatePawnForwardList(int x, int y, int color) {
		int yModifier = -1;
		if (color == BLACK) {
			yModifier = 1;
		}
		moves[x][y][color == WHITE ? PAWNATTACKBLACK : PAWNATTACKWHITE][0] = MOVE(x, y, x, (y + yModifier));
	}

	bool MoveCache::isValidKnightMove(int x, int y) {
		return abs(x) != abs(y);
	}

	int MoveCache::getXModifier(int eastWest) {
		switch (eastWest) {
			case EAST:
				return 1;
			case WEST:
				return -1;
			default:
				return 0;
		}
	}

	int MoveCache::getYModifier(int northSouth) {
		switch (northSouth) {
			case NORTH:
				return 1;
			case SOUTH:
				return -1;
			default:
				return 0;
		}
	}
#endif