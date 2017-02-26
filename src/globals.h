#ifndef Globals_h
#define Globals_h
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
	#define CHECKMATE 1000
	#define STALEMATE 0
	#define BLACK 1
	#define WHITE -1
	#define SOMEWHERE_OFF_BOARD 59
	#define GET_OPPOSING_COLOR(color) (color * -1)
	#define GET_DIRECTION(color) (color == WHITE ? -1 : 1)
	#define GET_OPPOSING_DIRECTION(color) (color == WHITE ? 1 : -1)
	#define GET_COLOR(i) (i > 6 ? BLACK : WHITE)
	#define IS_PAWN(i) (i == WHITE_PAWN || i == BLACK_PAWN)
	#define GET_ROW(i) (i / 16)
	#define FIRST_RANK(i) (i < 8)
	#define LAST_RANK(i) (i > 111)
	#define BLANK 0
	#define KNIGHT_MOVE_1 ROWS(2) + 1
	#define KNIGHT_MOVE_2 ROWS(2) - 1
	#define KNIGHT_MOVE_3 ROWS(1) + 2
	#define KNIGHT_MOVE_4 ROWS(1) - 2
	#define KNIGHT_MOVE_5 ROWS(-1) + 2
	#define KNIGHT_MOVE_6 ROWS(-1) - 2
	#define KNIGHT_MOVE_7 ROWS(-2) + 1
	#define KNIGHT_MOVE_8 ROWS(-2) - 1
	#define KING_MOVE_1 ROWS(1)
	#define KING_MOVE_2 ROWS(1) + 1
	#define KING_MOVE_3 1
	#define KING_MOVE_4 ROWS(-1) + 1
	#define KING_MOVE_5 ROWS(-1)
	#define KING_MOVE_6 ROWS(-1) - 1
	#define KING_MOVE_7 -1
	#define KING_MOVE_8 ROWS(1) - 1
	#define BLACK_ROOK_LEFT 0
	#define BLACK_ROOK_RIGHT 7
	#define BLACK_KING_POS 4
	#define BLACK_KING_CASTLE_LEFT 2
	#define BLACK_ROOK_CASTLE_LEFT 3
	#define BLACK_KING_CASTLE_RIGHT 6
	#define BLACK_ROOK_CASTLE_RIGHT 5
	#define WHITE_ROOK_LEFT 112
	#define WHITE_ROOK_RIGHT 119
	#define WHITE_KING_POS 116
	#define WHITE_KING_CASTLE_LEFT 114
	#define WHITE_ROOK_CASTLE_LEFT 115
	#define WHITE_KING_CASTLE_RIGHT 118
	#define WHITE_ROOK_CASTLE_RIGHT 117
	#define INITIAL_POSITION "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1"

#endif