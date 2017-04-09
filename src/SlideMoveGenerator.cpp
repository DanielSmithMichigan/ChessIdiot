#ifndef SlideMoveGenerator_cpp
#define SlideMoveGenerator_cpp
	#include "SlideMoveGenerator.h"

	SlideMoveGenerator::SlideMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) 
		: MoveGenerator(board, moveStack, attackedSquare) {
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
		int myColor = GET_COLOR(Board::squares[from]);
		while (ON_BOARD(to)) {
			int pieceAtLocation = Board::squares[to];
			if (pieceAtLocation != EMPTY_SPACE) {
				if (GET_COLOR(pieceAtLocation) != myColor) {
					generateMove(from, to);
				}
				break;
			}
			generateMove(from, to);
			to += delta;
		}
	}
#endif