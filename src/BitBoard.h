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
		inline uint64_t getBishopMoves(uint32_t location) {
			uint64_t occupancyMask = BishopOccupancyMasks[location] & Board::occupiedSquares;
			return (BishopPointers[location][(occupancyMask * BishopMagics[location]) >> BishopShifts[location]]) & ~Board::colors[COLOR];
		}

		template<uint32_t COLOR>
		inline uint64_t getRookMoves(uint32_t location) {
			uint64_t occupancyMask = RookOccupancyMasks[location] & Board::occupiedSquares;
			return (RookPointers[location][(occupancyMask * RookMagics[location]) >> RookShifts[location]]) & ~Board::colors[COLOR];
		}
	}
#endif