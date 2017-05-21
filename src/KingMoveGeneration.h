#ifndef KingMoveGeneration_h
#define KingMoveGeneration_h
	
	#include "SquareAttacked.h"
	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR> inline void generateCastle();
	template <uint32_t COLOR, bool QUIESCENCE> inline void generateAdjacentKingMoves();
	template <uint32_t COLOR, bool QUIESCENCE> inline void generateKingMoves();


	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateKingMoves() {
		generateAdjacentKingMoves<COLOR, QUIESCENCE>();
		if (!QUIESCENCE) {
			generateCastle<COLOR>();
		}
	}

	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateAdjacentKingMoves() {
		uint64_t kings = Board::pieces[KING] & Board::colors[COLOR];
		if (kings) {
			uint32_t kingLocation = popBit(kings);
			uint64_t allKingMoves = BitBoard::getAdjacentKingMoves<COLOR>(kingLocation);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allKingMoves;
			while(captureMoves) {
				MoveStack::push(move<CAPTURE>(kingLocation, popBit(captureMoves)));
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allKingMoves;
				while(nonCaptureMoves) {
					MoveStack::push(quietMove(kingLocation, popBit(nonCaptureMoves)));
				}
			}
		}
	}

	template <uint32_t COLOR>
	inline void generateCastle() {
		uint64_t rooks = Board::pieces[ROOK] & Board::colors[COLOR];
		uint64_t kings = Board::pieces[KING] & Board::colors[COLOR];
		uint32_t kingLocation = popBit(kings);
		if (squareAttacked<OPPOSING_COLOR(COLOR)>(kingLocation)) {
			return;
		}
		if (COLOR == WHITE
			&& Board::currentState->whiteCanCastleRight
			&& !(Board::occupiedSquares & CASTLE_RIGHT_OCCUPIED & row<7>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(61)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(62)) {
			MoveStack::push(move<CASTLE>(kingLocation, 62));
		}
		if (COLOR == WHITE
			&& Board::currentState->whiteCanCastleLeft
			&& !(Board::occupiedSquares & CASTLE_LEFT_OCCUPIED & row<7>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(58)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(59)) {
			MoveStack::push(move<CASTLE>(kingLocation, 58));
		}
		if (COLOR == BLACK
			&& Board::currentState->blackCanCastleRight
			&& !(Board::occupiedSquares & CASTLE_RIGHT_OCCUPIED & row<0>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(5)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(6)) {
			MoveStack::push(move<CASTLE>(kingLocation, 6));
		}

		if (COLOR == BLACK
			&& Board::currentState->blackCanCastleLeft
			&& !(Board::occupiedSquares & CASTLE_LEFT_OCCUPIED & row<0>())
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(2)
			&& !squareAttacked<OPPOSING_COLOR(COLOR)>(3)) {
			MoveStack::push(move<CASTLE>(kingLocation, 2));
		}
	}
#endif