#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		squares.resize(BOARD_SIZE);
		for (int i = 0; i < BOARD_SIZE; i++) {
			squares[i] = unique_ptr<Square>(new Square(i));
		}
		reset();
	}

	Board::~Board() {
	}

	void Board::reset() {
		for (int i = 0; i < BOARD_WIDTH; i++) {
			place(WHITE, PAWN, i + 48);
			place(BLACK, PAWN, i + 8);
		}
		place(BLACK, ROOK, 7);
		place(BLACK, ROOK, 0);
		place(BLACK, KNIGHT, 6);
		place(BLACK, KNIGHT, 1);
		place(BLACK, BISHOP, 5);
		place(BLACK, BISHOP, 2);
		place(BLACK, KING, 4);
		place(BLACK, QUEEN, 3);
		place(WHITE, ROOK, 63);
		place(WHITE, ROOK, 56);
		place(WHITE, KNIGHT, 62);
		place(WHITE, KNIGHT, 57);
		place(WHITE, BISHOP, 61);
		place(WHITE, BISHOP, 58);
		place(WHITE, QUEEN, 59);
		place(WHITE, KING, 60);
	}

	void Board::removeIndicatorColors() {
		for(int i = 0; i < BOARD_SIZE; i++) {
			squares[i]->resetFeatures();
		}
	}

	void Board::place(uint8_t color, uint8_t type, uint64_t location) {
		getPieceBoard(color, type) |= (uint64_t)1 << location;
		getColorBoard(color) |= (uint64_t)1 << location;
		OccupiedSpace |= (uint64_t)1 << location;
		squares[location]->setPiece(type, color);
	}

	uint64_t& Board::getPieceBoard(uint8_t color, uint8_t type) {
		switch(type) {
			case PAWN: 
				return color == BLACK ? BlackPawns : WhitePawns;
			case ROOK: 
				return color == BLACK ? BlackRooks : WhiteRooks;
			case KNIGHT: 
				return color == BLACK ? BlackKnights : WhiteKnights;
			case BISHOP: 
				return color == BLACK ? BlackBishops : WhiteBishops;
			case QUEEN: 
				return color == BLACK ? BlackQueens : WhiteQueens;
			case KING: 
				return color == BLACK ? BlackKings : WhiteKings;
		}
		throw "UncaughtException";
	}


	uint64_t& Board::getColorBoard(uint8_t color) {
		return color == BLACK ? BlackPieces : WhitePieces;
	}
#endif