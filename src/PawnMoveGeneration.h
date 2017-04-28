#ifndef PawnMoveGenerator_h
#define PawnMoveGenerator_h

	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR> inline void generatePawnMoves();

	template <uint32_t COLOR> inline void oneMoveUp();

	template <uint32_t COLOR> inline void twoMovesUp();

	template <uint32_t COLOR>
	inline void generatePawnMoves() {
		oneMoveUp<COLOR>();
		twoMovesUp<COLOR>();
	}

	template <uint32_t COLOR>
	inline void oneMoveUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];
		if (COLOR == WHITE) {
			pawnBoard <<= ROW;
		} else if (COLOR == BLACK) {
			pawnBoard >>= ROW;
		}
		pawnBoard &= ~Board::occupiedSquares;
		uint32_t moveIndex;
		while (pawnBoard) {
			moveIndex = popBit(pawnBoard);
			if (COLOR == WHITE) {
				MoveStack::push(quietMove(moveIndex + ROW, moveIndex));
			} else if (COLOR == BLACK) {
				MoveStack::push(quietMove(moveIndex - ROW, moveIndex));
			}
		}
	}

	template <uint32_t COLOR>
	inline void twoMovesUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];

		if (COLOR == WHITE) {
			pawnBoard &= row<6>();
		} else if (COLOR == BLACK) {
			pawnBoard &= row<1>();
		}

		if (COLOR == WHITE) {
			pawnBoard <<= rows<2>();
		} else if (COLOR == BLACK) {
			pawnBoard >>= rows<2>();
		}

		if (COLOR == WHITE) {
			pawnBoard &= ~(Board::occupiedSquares << ROW);
		} else if (COLOR == BLACK) {
			pawnBoard &= ~(Board::occupiedSquares >> ROW);
		}

		pawnBoard &= ~Board::occupiedSquares;

		uint32_t moveIndex;
		while (pawnBoard) {
			moveIndex = popBit(pawnBoard);
			if (COLOR == WHITE) {
				MoveStack::push(quietMove(moveIndex + rows<2>(), moveIndex));
			} else if (COLOR == BLACK) {
				MoveStack::push(quietMove(moveIndex - rows<2>(), moveIndex));
			}
		}
	}
#endif