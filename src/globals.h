#ifndef Globals_h
#define Globals_h
	#define MOVE_STACK_LIMIT 512
	#define MAX_DEPTH 24
	#define BOARD_SIZE 128
	#define BOARD_WIDTH 8
	#define ROWS(numColumns) (numColumns * 16)
	#define ON_BOARD(i) (!(i & 0x88))
	#define NOT_ON_BOARD(i) (i & 0x88)
	#define NORTH ROWS(1)
	#define NORTH_EAST 1 + ROWS(1)
	#define EAST 1
	#define SOUTH_EAST 1 + ROWS(-1)
	#define SOUTH ROWS(-1)
	#define SOUTH_WEST -1 + ROWS(-1)
	#define WEST -1
	#define NORTH_WEST -1 + ROWS(1)
	#define EMPTY_SPACE 0
	#define WHITE_PAWN 1
	#define WHITE_KNIGHT 2
	#define WHITE_BISHOP 3
	#define WHITE_ROOK 4
	#define WHITE_QUEEN 5
	#define WHITE_KING 6
	#define BLACK_PAWN 7
	#define BLACK_KNIGHT 8
	#define BLACK_BISHOP 9
	#define BLACK_ROOK 10
	#define BLACK_QUEEN 11
	#define BLACK_KING 12
	#define BLACK 1
	#define WHITE -1
	#define GET_COLOR(i) (i > 6 ? BLACK : WHITE)
	#define IS_PAWN(i) (i == WHITE_PAWN || i == BLACK_PAWN)
	#define FIRST_RANK(i) (i < 8)
	#define LAST_RANK(i) (i > 111)
	#define BLANK 0
#endif