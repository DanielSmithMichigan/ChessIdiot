#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		squares.resize(BOARD_WIDTH);
		for (int i = 0; i < BOARD_WIDTH; i++) {
			squares[i].resize(BOARD_WIDTH);
		}
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for(int y = 0; y < BOARD_WIDTH; y++) {
				squares[x][y] = unique_ptr<Square>(new Square(x, y));
			}
		}
		for (int i = 0; i < 2; i++) {
			colorBoards[i] = 0;
			for (int j = 0; j < 6; j++) {
				pieceBoards[i][j] = 0;
			}
		}
		initialize();
	}

	Board::~Board() {
	}

	void Board::initialize() {
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

	void Board::place(uint64_t color, uint64_t type, int x, int y) {
		pieceBoards[color][type] |= identityBoardFromXy(x, y);
		colorBoards[color] |= identityBoardFromXy(x, y);
		occupiedSpace |= identityBoardFromXy(x, y);
		squares[x][y]->setPiece(type, color);
	}

	void Board::remove(uint64_t color, uint64_t type, int x, int y) {
		pieceBoards[color][type] &= inverseIdentityBoardFromXy(x, y);
		colorBoards[color] &= inverseIdentityBoardFromXy(x, y);
		occupiedSpace &= inverseIdentityBoardFromXy(x, y);
		squares[x][y]->setPiece(type, color);
	}

	void Board::highlightAllMatches(uint64_t bitboard) {
		for (int x = 0; x < BOARD_WIDTH; x++) {
			for(int y = 0; y < BOARD_WIDTH; y++) {
				squares[x][y]->highlightIfMatches(bitboard);
			}
		}
	}

	uint64_t Board::getPieceAtSquare(int x, int y) {
		return squares[x][y]->piece;
	}
#endif