#ifndef BitBoard_h
#define BitBoard_h
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

		extern uint64_t KnightBoards[64];
		extern uint64_t KingBoards[64];
		extern uint64_t lines[64][64];
		extern uint64_t betweenLines[64][64];

		void InitBitBoards();
		void InitRookBitBoards();
		void InitBishopBitBoards();


		inline uint64_t getBishopMovesWithoutCollision(uint32_t location, uint64_t occupiedSquares) {
			uint64_t occupancyMask = BishopOccupancyMasks[location] & occupiedSquares;
			return (BishopPointers[location][(occupancyMask * BishopMagics[location]) >> BishopShifts[location]]);
		}

		template<uint32_t COLOR>
		inline uint64_t getBishopMoves(uint32_t location, uint64_t occupiedSquares, uint64_t myPieces) {
			return getBishopMovesWithoutCollision(location, occupiedSquares) & ~myPieces;
		}

		inline uint64_t getRookMovesWithoutCollision(uint32_t location, uint64_t occupiedSquares) {
			uint64_t occupancyMask = RookOccupancyMasks[location] & occupiedSquares;
			return (RookPointers[location][(occupancyMask * RookMagics[location]) >> RookShifts[location]]);
		}

		template<uint32_t COLOR>
		inline uint64_t getRookMoves(uint32_t location, uint64_t occupiedSquares, uint64_t myPieces) {
			return getRookMovesWithoutCollision(location, occupiedSquares) & ~myPieces;
		}

		template<uint32_t COLOR>
		inline uint64_t getAdjacentKingMoves(uint32_t location, uint64_t myPieces) {
			return KingBoards[location] & ~myPieces;
		}

		template<uint32_t COLOR>
		inline uint64_t getKnightMoves(uint32_t location, uint64_t myPieces) {
			return KnightBoards[location] & ~myPieces;
		}

		template<PieceType PIECE_TYPE>
		inline void InitLines() {
			uint64_t attacks[64];
			uint64_t attacksI, attacksJ;
			for (uint32_t i = 0; i < BOARD_SIZE; i++) {
				if (PIECE_TYPE == ROOK) {
					attacks[i] = getRookMovesWithoutCollision(i, 0);
				} else if (PIECE_TYPE == BISHOP) {
					attacks[i] = getBishopMovesWithoutCollision(i, 0);
				}
			}
			for (uint32_t i = 0; i < BOARD_SIZE; i++) {
				uint64_t pieceBoardI = getPieceBoard(i);
				for (uint32_t j = 0; j < BOARD_SIZE; j++) {
					uint64_t pieceBoardJ = getPieceBoard(j);
					if (!(attacks[i] & pieceBoardJ)) {
						continue;
					}
					lines[i][j] = (attacks[i] & attacks[j]) | pieceBoardI | pieceBoardJ;
					if (PIECE_TYPE == ROOK) {
						betweenLines[i][j] = getRookMovesWithoutCollision(i, getPieceBoard(j)) & getRookMovesWithoutCollision(j, getPieceBoard(i)) | pieceBoardI | pieceBoardJ;
					} else if (PIECE_TYPE == BISHOP) {
						betweenLines[i][j] = getBishopMovesWithoutCollision(i, getPieceBoard(j)) & getBishopMovesWithoutCollision(j, getPieceBoard(i)) | pieceBoardI | pieceBoardJ;
					}
				}
			}
		}

		inline bool aligned(uint32_t i, uint32_t j, uint64_t k) {
			return lines[i][j] & k;
		}
	}
#endif