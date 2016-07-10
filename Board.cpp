#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		WhitePawns = 0;
		WhiteRooks = 0;
		WhiteKnights = 0;
		WhiteBishops = 0;
		WhiteQueens = 0;
		WhiteKings = 0;
		BlackPawns = 0;
		BlackRooks = 0;
		BlackKnights = 0;
		BlackBishops = 0;
		BlackQueens = 0;
		BlackKings = 0;
		OccupiedSpace = 0;
		for (int i = 0; i < 8; i++) {
			place(WHITE, PAWN, i + 48);
			place(BLACK, PAWN, i + 8);
		}
		place(BLACK, ROOK, 7);
		place(BLACK, ROOK, 0);
		place(BLACK, KNIGHT, 6);
		place(BLACK, KNIGHT, 1);
		place(BLACK, BISHOP, 5);
		place(BLACK, BISHOP, 2);
		place(BLACK, QUEEN, 4);
		place(BLACK, KING, 3);
		place(WHITE, ROOK, 63);
		place(WHITE, ROOK, 56);
		place(WHITE, KNIGHT, 62);
		place(WHITE, KNIGHT, 57);
		place(WHITE, BISHOP, 61);
		place(WHITE, BISHOP, 58);
		place(WHITE, QUEEN, 59);
		place(WHITE, KING, 60);
	}

	Board::~Board() {

	}

	void Board::place(uint8_t color, uint8_t type, uint64_t location) {
		// Pieces[location] = unique_ptr<Piece>(new Piece(type, color));
		getPieceBoard(color, type) |= (uint64_t)1 << location;
		getColorBoard(color) |= (uint64_t)1 << location;
		OccupiedSpace |= (uint64_t)1 << location;
	}

	uint64_t& Board::getPieceBoard(uint8_t color, uint8_t type) {
		switch(type) {
			case PAWN: 
				if (color == BLACK) {
					return BlackPawns;
				} else {
					return WhitePawns;
				}
			break;
			case ROOK: 
				if (color == BLACK) {
					return BlackRooks;
				} else {
					return WhiteRooks;
				}
			break;
			case KNIGHT: 
				if (color == BLACK) {
					return BlackKnights;
				} else {
					return WhiteKnights;
				}
			break;
			case BISHOP: 
				if (color == BLACK) {
					return BlackBishops;
				} else {
					return WhiteBishops;
				}
			break;
			case QUEEN: 
				if (color == BLACK) {
					return BlackQueens;
				} else {
					return WhiteQueens;
				}
			break;
			case KING: 
				if (color == BLACK) {
					return BlackKings;
				} else {
					return WhiteKings;
				}
			break;
		}
		throw "UncaughtException";
	}


	uint64_t& Board::getColorBoard(uint8_t color) {
		if (color == BLACK) {
			return BlackPieces;
		} else {
			return WhitePieces;
		}
	}
#endif