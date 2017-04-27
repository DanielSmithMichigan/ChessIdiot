#ifndef PawnMoveGenerator_h
#define PawnMoveGenerator_h

	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint8_t COLOR> inline void generatePawnMoves();

	template <uint8_t COLOR> inline void oneMoveUp();

	template <uint8_t COLOR>
	inline void generatePawnMoves() {
		oneMoveUp<COLOR>();
	}

	template <uint8_t COLOR>
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
				MoveStack::push(quietMove(moveIndex + ROW, moveIndex));
			} else if (COLOR == BLACK) {
				MoveStack::push(quietMove(moveIndex - ROW, moveIndex));
			}
		}
	}
#endif