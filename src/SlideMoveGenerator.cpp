#ifndef SlideMoveGenerator_cpp
#define SlideMoveGenerator_cpp
	#include "SlideMoveGenerator.h"

	//FULL_MOVE(from,to,captured,enPassant,firstMove,promotedPiece,castle)

	SlideMoveGenerator::SlideMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: MoveGenerator(board, moveStack) {
	}

	SlideMoveGenerator::~SlideMoveGenerator() {

	}

	void SlideMoveGenerator::generateMoves(int from) {
		if (canMoveNorth) {
			generateSlideMove(from, NORTH);
		}
		if (canMoveNorthEast) {
			generateSlideMove(from, NORTH_EAST);
		}
		if (canMoveEast) {
			generateSlideMove(from, EAST);
		}
		if (canMoveSouthEast) {
			generateSlideMove(from, SOUTH_EAST);
		}
		if (canMoveSouth) {
			generateSlideMove(from, SOUTH);
		}
		if (canMoveSouthWest) {
			generateSlideMove(from, SOUTH_WEST);
		}
		if (canMoveWest) {
			generateSlideMove(from, WEST);
		}
		if (canMoveNorthWest) {
			generateSlideMove(from, NORTH_WEST);
		}

	}

	void SlideMoveGenerator::generateSlideMove(int from, int delta) {
		int to = from + delta;
		while (ON_BOARD(to)) {
			if (board->squares[to] != EMPTY_SPACE) {
				if (GET_COLOR(board->squares[to]) != GET_COLOR(board->squares[from])) {
					generateMove(from, to);
				}
				break;
			}
			generateMove(from, to);
			to += delta;
		}
	}
#endif