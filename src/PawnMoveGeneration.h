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
		uint32_t move;
		if (pawnBoard) {
			moveIndex = popBit(pawnBoard);
			if (COLOR == WHITE && DIRECTION == LEFT) {
				move = move<EN_PASSANT>(moveIndex + ROW + 1, moveIndex);
			} else if (COLOR == WHITE && DIRECTION == RIGHT) {
				move = move<EN_PASSANT>(moveIndex + ROW - 1, moveIndex);
			} else if (COLOR == BLACK && DIRECTION == LEFT) {
				move = move<EN_PASSANT>(moveIndex - ROW + 1, moveIndex);
			} else if (COLOR == BLACK && DIRECTION == RIGHT) {
				move = move<EN_PASSANT>(moveIndex - ROW - 1, moveIndex);
			}
			// Board::doMove(move);
			// if (!canTakeKing()) {
				MoveStack::instance->push(move);
			// }
			// Board::undoMove();
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
		uint32_t to, from, fromBoard, pinned;
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
			pinned = fromBoard & Board::currentState->pinnedToKing[COLOR];
			if (pinned
				&& !BitBoard::aligned(kingLocation, to, fromBoard)) {
				continue;
			} 
			MoveStack::instance->push(quietMove(from, to));
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
			fromBoard = getPieceBoard(from);
			pinned = fromBoard & Board::currentState->pinnedToKing[COLOR];
			if (pinned) {
				continue;
			}
			MoveStack::instance->push(move<PROMOTION>(from, to, QUEEN));
			MoveStack::instance->push(move<PROMOTION>(from, to, ROOK));
			MoveStack::instance->push(move<PROMOTION>(from, to, BISHOP));
			MoveStack::instance->push(move<PROMOTION>(from, to, KNIGHT));
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

		uint32_t moveIndex;
		while (nonPromotionMoves) {
			moveIndex = popBit(nonPromotionMoves);
			if (COLOR == WHITE) {
				MoveStack::instance->push(quietMove(moveIndex + ROW, moveIndex));
			} else if (COLOR == BLACK) {
				MoveStack::instance->push(quietMove(moveIndex - ROW, moveIndex));
			}
		}

		uint64_t promotionMoves = pawnBoard & PROMOTION_ROWS; 
		uint32_t from;
		uint64_t pinned;
		while (promotionMoves) {
			moveIndex = popBit(promotionMoves);
			if (COLOR == WHITE) {
				from = moveIndex + ROW;
			} else if (COLOR == BLACK) {
				from = moveIndex - ROW;
			}
			pinned = getPieceBoard(from) & Board::currentState->pinnedToKing[COLOR];
			if (pinned
				&& !BitBoard::aligned(kingLocation, moveIndex, getPieceBoard(from))) {
				continue;
			}
			MoveStack::instance->push(move<PROMOTION>(from, moveIndex, QUEEN));
			MoveStack::instance->push(move<PROMOTION>(from, moveIndex, ROOK));
			MoveStack::instance->push(move<PROMOTION>(from, moveIndex, BISHOP));
			MoveStack::instance->push(move<PROMOTION>(from, moveIndex, KNIGHT));
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
		uint64_t pinned;
		while (pawnBoard) {
			to = popBit(pawnBoard);
			if (COLOR == WHITE) {
				from = to + rows<2>();
			} else if (COLOR == BLACK) {
				from = to - rows<2>();
			}
			pinned = getPieceBoard(from) & Board::currentState->pinnedToKing[COLOR];
			if (pinned
				&& !BitBoard::aligned(kingLocation, to, getPieceBoard(from))) {
				continue;
			}
			MoveStack::instance->push(move<PAWN_DOUBLE>(from, to));
		}
	}
#endif