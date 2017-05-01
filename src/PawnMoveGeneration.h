#ifndef PawnMoveGenerator_h
#define PawnMoveGenerator_h

	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, uint32_t NUM_ROWS> inline void pushPawns(uint64_t &pawnBoard);

	template <uint32_t COLOR> inline void generatePawnMoves();

	template <uint32_t COLOR> inline void oneMoveUp();

	template <uint32_t COLOR> inline void twoMovesUp();

	template <uint32_t COLOR, uint32_t DIRECTION> inline void twoMovesUp();

	template <uint32_t COLOR, uint32_t DIRECTION> inline void attack();

	template <uint32_t COLOR>
	inline void generatePawnMoves() {
		oneMoveUp<COLOR>();
		twoMovesUp<COLOR>();
		attack<COLOR, LEFT>();
		attack<COLOR, RIGHT>();
	}

	template <uint32_t COLOR, uint32_t DIRECTION> 
	inline void attack() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];

		pushPawns<COLOR, 1>(pawnBoard);

		if (DIRECTION == LEFT) {
			pawnBoard &= ~file<0>();
			pawnBoard <<= 1;
		} else if (DIRECTION == RIGHT) {
			pawnBoard &= ~file<7>();
			pawnBoard >>= 1;
		}
		
		pawnBoard &= Board::colors[OPPOSING_COLOR(COLOR)];

		uint64_t nonPromotionMoves = pawnBoard & ~PROMOTION_ROWS;

		uint32_t moveIndex;
		while (nonPromotionMoves) {
			moveIndex = popBit(nonPromotionMoves);
			if (COLOR == WHITE && DIRECTION == LEFT) {
				MoveStack::push(move<CAPTURE>(moveIndex + ROW + 1, moveIndex));
			} else if (COLOR == WHITE && DIRECTION == RIGHT) {
				MoveStack::push(move<CAPTURE>(moveIndex + ROW - 1, moveIndex));
			} else if (COLOR == BLACK && DIRECTION == LEFT) {
				MoveStack::push(move<CAPTURE>(moveIndex - ROW + 1, moveIndex));
			} else if (COLOR == BLACK && DIRECTION == RIGHT) {
				MoveStack::push(move<CAPTURE>(moveIndex - ROW - 1, moveIndex));
			}
		}

		uint64_t promotionMoves = pawnBoard & PROMOTION_ROWS; 

	}

	template <uint32_t COLOR>
	inline void oneMoveUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];

		pushPawns<COLOR, 1>(pawnBoard);

		pawnBoard &= ~Board::occupiedSquares;

		uint64_t nonPromotionMoves = pawnBoard & ~PROMOTION_ROWS;

		uint32_t moveIndex;
		while (nonPromotionMoves) {
			moveIndex = popBit(nonPromotionMoves);
			if (COLOR == WHITE) {
				MoveStack::push(quietMove(moveIndex + ROW, moveIndex));
			} else if (COLOR == BLACK) {
				MoveStack::push(quietMove(moveIndex - ROW, moveIndex));
			}
		}

		uint64_t promotionMoves = pawnBoard & PROMOTION_ROWS; 

		// Create promotion moves
	}

	template <uint32_t COLOR>
	inline void twoMovesUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];

		if (COLOR == WHITE) {
			pawnBoard &= row<6>();
		} else if (COLOR == BLACK) {
			pawnBoard &= row<1>();
		}

		pushPawns<COLOR, 2>(pawnBoard);

		if (COLOR == WHITE) {
			pawnBoard &= ~(Board::occupiedSquares << ROW);
		} else if (COLOR == BLACK) {
			pawnBoard &= ~(Board::occupiedSquares >> ROW);
		}

		pawnBoard &= ~Board::occupiedSquares;

		uint32_t from, to;
		while (pawnBoard) {
			to = popBit(pawnBoard);
			if (COLOR == WHITE) {
				from = to + rows<2>();
			} else if (COLOR == BLACK) {
				from = to - rows<2>();
			}
			MoveStack::push(move<PAWN_DOUBLE>(from, to));
		}
	}

	template <uint32_t COLOR, uint32_t NUM_ROWS> 
	inline void pushPawns(uint64_t &pawnBoard) {
		if (COLOR == WHITE) {
			pawnBoard <<= rows<NUM_ROWS>();
		} else if (COLOR == BLACK) {
			pawnBoard >>= rows<NUM_ROWS>();
		}
	}
#endif