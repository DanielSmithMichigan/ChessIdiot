#ifndef PawnMoveGenerator_cpp
#define PawnMoveGenerator_cpp
	#include "PawnMoveGeneration.h"

	template <bool COLOR>
	inline void generatePawnMoves() {
		oneMoveUp<COLOR>();
	}

	template <bool COLOR>
	inline void oneMoveUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];
		if (COLOR == WHITE) {
			pawnBoard <<= ROW;
		} else if (COLOR == BLACK) {
			pawnBoard >>= ROW;
		}
		pawnBoard &= ~Board::occupiedSquares;
		uint8_t moveIndex;
		while (pawnBoard) {
			moveIndex = popBit(pawnBoard);
			if (COLOR == WHITE) {
				MoveStack::push(quietMove(moveIndex, moveIndex - ROW));
			} else if (COLOR == BLACK) {
				MoveStack::push(quietMove(moveIndex, moveIndex + ROW));
			}
		}
	}
#endif