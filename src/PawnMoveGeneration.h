#ifndef PawnMoveGenerator_h
#define PawnMoveGenerator_h

	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"
	#include "SquareAttacked.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generatePawnMoves();

	template <uint32_t COLOR> inline void oneMoveUp();

	template <uint32_t COLOR> inline void twoMovesUp();

	template <uint32_t COLOR, uint32_t DIRECTION> inline void twoMovesUp();

	template <uint32_t COLOR, uint32_t DIRECTION> inline void attack();

	template <uint32_t COLOR, uint32_t DIRECTION> inline void enPassant();

	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generatePawnMoves() {
		if (!QUIESCENCE) {
			oneMoveUp<COLOR>();
			twoMovesUp<COLOR>();
		}
		attack<COLOR, LEFT>();
		attack<COLOR, RIGHT>();
		enPassant<COLOR, LEFT>();
		enPassant<COLOR, RIGHT>();
	}

	template <uint32_t COLOR, uint32_t DIRECTION> 
	inline void enPassant() {
		uint32_t enPassantTarget = Board::currentState->enPassantTarget;
		if (enPassantTarget == NO_EN_PASSANT) {
			return;
		}

		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];
		uint64_t enPassantBoard = getPieceBoard(enPassantTarget);

		pushPawns<COLOR, 1>(pawnBoard);
		shiftPawns<DIRECTION>(pawnBoard);
		
		pawnBoard &= enPassantBoard;

		uint32_t moveIndex;
		uint32_t from;
		if (pawnBoard) {
			moveIndex = popBit(pawnBoard);
			if (COLOR == WHITE && DIRECTION == LEFT) {
				from = moveIndex + ROW + 1;
			} else if (COLOR == WHITE && DIRECTION == RIGHT) {
				from = moveIndex + ROW - 1;
			} else if (COLOR == BLACK && DIRECTION == LEFT) {
				from = moveIndex - ROW + 1;
			} else if (COLOR == BLACK && DIRECTION == RIGHT) {
				from = moveIndex - ROW - 1;
			}
			MoveStack::instance->checkAndPushMove(COLOR, EN_PASSANT, from, moveIndex);
		}

	}

	template <uint32_t COLOR, uint32_t DIRECTION> 
	inline void attack() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];
		uint64_t kingBoard = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kingBoard);

		pushPawns<COLOR, 1>(pawnBoard);

		shiftPawns<DIRECTION>(pawnBoard);
		
		pawnBoard &= Board::colors[OPPOSING_COLOR(COLOR)];

		uint64_t nonPromotionMoves = pawnBoard & ~PROMOTION_ROWS;
		uint64_t nonPromotionMove;
		uint32_t to, from, fromBoard;
		while (nonPromotionMoves) {
			to = popBit(nonPromotionMoves);
			if (COLOR == WHITE && DIRECTION == LEFT) {
				from = to + ROW + 1;
			} else if (COLOR == WHITE && DIRECTION == RIGHT) {
				from = to + ROW - 1;
			} else if (COLOR == BLACK && DIRECTION == LEFT) {
				from = to - ROW + 1;
			} else if (COLOR == BLACK && DIRECTION == RIGHT) {
				from = to - ROW - 1;
			}
			fromBoard = getPieceBoard(from);
			MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, from, to);
		}

		uint64_t promotionMoves = pawnBoard & PROMOTION_ROWS; 
		while (promotionMoves) {
			to = popBit(promotionMoves);
			if (COLOR == WHITE && DIRECTION == LEFT) {
				from = to + ROW + 1;
			} else if (COLOR == WHITE && DIRECTION == RIGHT) {
				from = to + ROW - 1;
			} else if (COLOR == BLACK && DIRECTION == LEFT) {
				from = to - ROW + 1;
			} else if (COLOR == BLACK && DIRECTION == RIGHT) {
				from = to - ROW - 1;
			}
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, QUEEN);
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, ROOK);
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, BISHOP);
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, KNIGHT);
		}

	}

	template <uint32_t COLOR>
	inline void oneMoveUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];
		uint64_t kingBoard = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kingBoard);

		pushPawns<COLOR, 1>(pawnBoard);

		pawnBoard &= ~Board::occupiedSquares;

		uint64_t nonPromotionMoves = pawnBoard & ~PROMOTION_ROWS;

		uint32_t to, from;
		while (nonPromotionMoves) {
			to = popBit(nonPromotionMoves);
			if (COLOR == WHITE) {
				from = to + ROW;
			} else if (COLOR == BLACK) {
				from = to - ROW;
			}
			MoveStack::instance->checkAndPushMove(COLOR, CLASSIC, from, to);
		}

		uint64_t promotionMoves = pawnBoard & PROMOTION_ROWS; 
		while (promotionMoves) {
			to = popBit(promotionMoves);
			if (COLOR == WHITE) {
				from = to + ROW;
			} else if (COLOR == BLACK) {
				from = to - ROW;
			}
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, QUEEN);
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, ROOK);
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, BISHOP);
			MoveStack::instance->checkAndPushMove(COLOR, PROMOTION, from, to, KNIGHT);
		}
	}

	template <uint32_t COLOR>
	inline void twoMovesUp() {
		uint64_t pawnBoard = Board::pieces[PAWN] & Board::colors[COLOR];
		uint64_t kingBoard = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kingBoard);

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
			MoveStack::instance->checkAndPushMove(COLOR, PAWN_DOUBLE, from, to);
		}
	}
#endif