#ifndef RookMoveGeneration_h
#define RookMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateRookMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateRookMoves() {
		uint64_t rooks = Board::pieces[ROOK] & Board::colors[COLOR];
		while(rooks) {
			uint32_t rookLocation = popBit(rooks);
			uint64_t allRookMoves = BitBoard::getRookMoves<COLOR>(rookLocation);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allRookMoves;
			while(captureMoves) {
				MoveStack::push(move<CAPTURE>(rookLocation, popBit(captureMoves)));
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allRookMoves;
				while(nonCaptureMoves) {
					MoveStack::push(move<CAPTURE>(rookLocation, popBit(nonCaptureMoves)));
				}
			}
		}
	}
#endif