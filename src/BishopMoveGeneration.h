#ifndef BishopMoveGeneration_h
#define BishopMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;
	template <uint32_t COLOR> inline void generateBishopMoves();

	template <uint32_t COLOR>
	inline void generateBishopMoves() {
		uint64_t bishopBoard = Board::pieces[BISHOP] & Board::colors[COLOR];
		uint32_t bishopLocation;
		uint64_t bishopMoves;
		while(bishopBoard) {
			bishopLocation = popBit(bishopBoard);
			uint64_t allMoves = BitBoard::getBishopMoves<COLOR>(bishopLocation);
			uint64_t nonCaptureMoves = allMoves & ~Board::colors[OPPOSING_COLOR(COLOR)];
			while(nonCaptureMoves) {
				MoveStack::push(quietMove(bishopLocation, popBit(nonCaptureMoves)));
			}
			uint64_t captureMoves = allMoves & Board::colors[OPPOSING_COLOR(COLOR)];
			while(captureMoves) {
				MoveStack::push(move<CAPTURE>(bishopLocation, popBit(captureMoves)));
			}
		}
	}
#endif