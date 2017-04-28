#ifndef Globals_h
#define Globals_h
	#include <stdint.h>
	const uint8_t BOARD_SIZE = 64;
	const uint8_t ROW = 8;
	template <int x>
	inline int rows() {return x * ROW;}
	template <int x>
	inline uint64_t row() {return (uint64_t)255 << ((7 - x) * ROW);}
	#define ROWS(x) (x * ROW)
	#define GET_ROW(x) (x / ROW)
	enum Color {
		WHITE, BLACK, BLANK
	};
	enum PieceType {
		EMPTY_SPACE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
		cPieceType = 7
	};
#endif