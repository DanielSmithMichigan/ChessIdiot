#ifndef BishopMoveGeneration_h
#define BishopMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateBishopMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateBishopMoves() {
		uint64_t bishops = Board::pieces[BISHOP] & Board::colors[COLOR];
		while(bishops) {
			uint32_t bishopLocation = popBit(bishops);
			uint64_t allBishopMoves = BitBoard::getBishopMoves<COLOR>(bishopLocation);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allBishopMoves;
			while(captureMoves) {
				MoveStack::push(move<CAPTURE>(bishopLocation, popBit(captureMoves)));
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allBishopMoves;
				while(nonCaptureMoves) {
					MoveStack::push(quietMove(bishopLocation, popBit(nonCaptureMoves)));
				}
			}
		}
	}
#endif