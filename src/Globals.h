#ifndef Globals_h
#define Globals_h
	#include <stdint.h>
	const uint32_t BOARD_SIZE = 64;
	const uint32_t ROW = 8;
	template <int x>
	inline int rows() {return x * ROW;}
	template <int x>
	inline uint64_t row() {return (uint64_t)255 << ((7 - x) * ROW);}
	template <int x>
	inline uint64_t file() {return (uint64_t)0x8080808080808080 >> x;}
	#define ROWS(x) (x * ROW)
	#define GET_ROW(x) (x / ROW)
	enum Direction {
		LEFT, RIGHT
	};
	enum Color {
		BLANK, WHITE = 1, BLACK = 2
	};
	enum PieceType {
		EMPTY_SPACE, PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING,
		cPieceType = 7
	};
	#define OPPOSING_COLOR(x) (x == WHITE ? BLACK : WHITE)
	#define PROMOTION_ROWS 0xFF000000000000FF;
#endif