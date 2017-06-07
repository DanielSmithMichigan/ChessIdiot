#ifndef PiecesValue_h
#define PiecesValue_h
	#include "Board.h"
	#include "Utility.h"
	#include <stdint.h>
	#include <iostream>

	using namespace std;

	namespace PiecesValue {
		extern int Pawn[64];
		extern int Knight[64];
		extern int Bishop[64];
		extern int Rook[64];
		extern int Queen[64];
		extern int King[64];
		extern int Mirror[64];
		template <uint32_t COLOR>
		inline int getValue(uint32_t piece, uint32_t location) {
			if (COLOR == WHITE) {
				location = Mirror[location];
			}
			if (piece == PAWN) {
				return Pawn[location];
			} else if (piece == KNIGHT) {
				return Knight[location];
			} else if (piece == BISHOP) {
				return Bishop[location];
			} else if (piece == ROOK) {
				return Rook[location];
			} else if (piece == QUEEN) {
				return Queen[location];
			} else if (piece == KING) {
				return King[location];
			} else {
				return 0;
			}
		}
	}
#endif