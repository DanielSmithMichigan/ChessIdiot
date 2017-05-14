#ifndef QueenMoveGeneration_h
#define QueenMoveGeneration_h

	#include "BitBoard.h"
	#include "Globals.h"
	#include "Board.h"
	#include "Lsb.h"
	#include "MoveStack.h"
	#include "Move.h"

	using namespace std;

	template <uint32_t COLOR, bool QUIESCENCE> inline void generateQueenMoves();
	template <uint32_t COLOR, bool QUIESCENCE>
	inline void generateQueenMoves() {
		uint64_t queens = Board::pieces[Queen] & Board::colors[COLOR];
		while(queens) {
			uint32_t queenLocation = popBit(queens);
			uint64_t allQueenMoves = BitBoard::getBishopMoves<COLOR>(queenLocation) | BitBoard::getRookMoves<COLOR>(queenLocation);
			uint64_t captureMoves = Board::colors[OPPOSING_COLOR(COLOR)] & allQueenMoves;
			while(captureMoves) {
				MoveStack::push(move<CAPTURE>(queenLocation, popBit(captureMoves)));
			}
			if (!QUIESCENCE) {
				uint64_t nonCaptureMoves = ~Board::colors[OPPOSING_COLOR(COLOR)] & allQueenMoves;
				while(nonCaptureMoves) {
					MoveStack::push(move<CAPTURE>(queenLocation, popBit(nonCaptureMoves)));
				}
			}
		}
	}
#endif