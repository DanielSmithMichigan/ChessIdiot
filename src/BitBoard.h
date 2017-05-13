#ifndef BitBoard_h
#define BitBoard_h
	#include "Board.h"
	#include "Utility.h"
	#include <stdint.h>
	#include <iostream>

	using namespace std;

	namespace BitBoard {
		extern uint64_t RookOccupancyMasks[64];
		extern uint64_t BishopOccupancyMasks[64];
		extern uint64_t RookMagics[64];
		extern uint64_t BishopMagics[64];
		extern uint64_t *RookPointers[64];
		extern uint64_t *BishopPointers[64];
		extern uint64_t RookAttacks[102400];
		extern uint64_t BishopAttacks[5248];
		extern uint64_t RookShifts[64];
		extern uint64_t BishopShifts[64];

		void InitBitBoards();
		void InitRookBitBoards();
		void InitBishopBitBoards();
		template<uint32_t COLOR>
		inline uint64_t getBishopMoves(int location) {
			return (BishopPointers[location][((BishopOccupancyMasks[location] & Board::occupiedSquares) * BishopMagics[location]) >> BishopShifts[location]]) & ~Board::colors[OPPOSING_COLOR(COLOR)];
		}
	}
#endif