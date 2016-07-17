#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		rookMoveGenerator.reset(new RookMoveGenerator());
		squares.resize(BOARD_WIDTH);
		for (int i = 0; i < BOARD_WIDTH; i++) {
			squares[i].resize(BOARD_WIDTH);
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for(int y = 0; y < BOARD_WIDTH; y++) {
				squares[x][y] = unique_ptr<Square>(new Square(x, y));
			}
		}
		reset();
	}

	Board::~Board() {
	}

	void Board::reset() {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			place(WHITE, PAWN, x, 6);
			place(BLACK, PAWN, x, 1);
		}
		place(BLACK, ROOK, 7, 0);
		place(WHITE, ROOK, 7, 7);
		place(BLACK, ROOK, 0, 0);
		place(WHITE, ROOK, 0, 7);
		place(BLACK, KNIGHT, 6, 0);
		place(WHITE, KNIGHT, 6, 7);
		place(BLACK, KNIGHT, 1, 0);
		place(WHITE, KNIGHT, 1, 7);
		place(BLACK, BISHOP, 5, 0);
		place(WHITE, BISHOP, 5, 7);
		place(BLACK, BISHOP, 2, 0);
		place(WHITE, BISHOP, 2, 7);
		place(BLACK, KING, 4, 0);
		place(WHITE, KING, 4, 7);
		place(BLACK, QUEEN, 3, 0);
		place(WHITE, QUEEN, 3, 7);
	}

	void Board::removeIndicatorColors() {
		for(int x = 0; x < BOARD_WIDTH; x++) {
			for (int y = 0; y < BOARD_WIDTH; y++) {
				squares[x][y]->resetFeatures();
			}
		}
	}

	void Board::place(uint8_t color, uint8_t type, int x, int y) {
		getPieceBoard(color, type) |= (uint64_t)1 << xyToInt(x, y);
		getColorBoard(color) |= (uint64_t)1 << xyToInt(x, y);
		OccupiedSpace |= (uint64_t)1 << xyToInt(x, y);
		squares[x][y]->setPiece(type, color);
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

	void Board::highlightAllMatches(uint8_t bitboard) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for(int y = 0; y < BOARD_WIDTH; y++) {
				squares[x][y]->highlightIfMatches(bitboard);
			}
		}
	}

	void Board::highlightMovesAt(int x, int y) {
		uint8_t piece = squares[x][y]->piece;
		uint8_t moveBoard;
		switch(piece) {
			case ROOK:
				moveBoard = rookMoveGenerator->movesAt(x, y);
			break;
		}
		highlightAllMatches(moveBoard);
	}
#endif