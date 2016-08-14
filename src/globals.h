#ifndef Globals_h
#define Globals_h
	#define BLACK 0
	#define WHITE 1
	#define EMPTY_SPACE 0
	#define PAWN 1
	#define ROOK 2
	#define KNIGHT 3
	#define BISHOP 4
	#define QUEEN 5
	#define KING 6
	#define BOARD_SIZE 64
	#define BOARD_WIDTH 8
	#define SQUARE_WIDTH 5
	#define SQUARE_HEIGHT 3
	#define BOARD_SCREEN_WIDTH BOARD_SIZE * SQUARE_WIDTH / BOARD_WIDTH
	#define BOARD_SCREEN_HEIGHT BOARD_SIZE * SQUARE_HEIGHT / BOARD_WIDTH
	#define SQUARE_CENTER_X 2
	#define SQUARE_CENTER_Y 1
	#define MARGIN_HORIZONTAL 5
	#define MARGIN_VERTICAL 3
	#define HIGHLIGHT 0
	#define SELECT 1
	#define NORTH 0
	#define NORTHEAST 1
	#define EAST 2
	#define SOUTHEAST 3
	#define SOUTH 4
	#define SOUTHWEST 5
	#define WEST 6
	#define NORTHWEST 7
	#define KNIGHTMOVES 8
	#define PAWNATTACKWHITE 9
	#define PAWNATTACKBLACK 10
	#define PAWNFORWARDWHITE 11
	#define PAWNFORWARDBLACK 12
#endif