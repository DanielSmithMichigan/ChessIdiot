#ifndef KingMoveGeneration_h
#define KingMoveGeneration_h

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
					MoveStack::push(move<CAPTURE>(kingLocation, popBit(nonCaptureMoves)));
				}
			}
		}
	}

	template <uint32_t COLOR>
	inline void generateCastle() {
		uint64_t rooks = Board::pieces[KING] & Board::colors[COLOR];
		if (COLOR == WHITE
			&& (rooks & 1)
			&& Board::currentState->whiteCanCastleRight) {

		}
	}
#endif