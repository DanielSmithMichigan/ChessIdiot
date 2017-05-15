#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	State* Board::currentState = new State();
	uint32_t Board::turn = 0;
	uint64_t Board::occupiedSquares = 0;
	uint64_t Board::colors[3] = {};
	uint64_t Board::pieces[8] = {};
	uint32_t Board::piecesIndex[64] = {};
	uint32_t Board::colorsIndex[64] = {};

	Board::Board() {
	}

	Board::~Board() {
	}

	void Board::doMove(uint32_t move) {
		uint32_t from = FROM(move);
		uint32_t to = TO(move);
		uint32_t specialMove = SPECIAL_MOVE(move);
		uint32_t specialMovePiece = PIECE(move);
		uint32_t piece = piecesIndex[from];
		uint32_t color = colorsIndex[from];

		increaseStateDepth();

		currentState->move = move;

		if (specialMove == EN_PASSANT) {
			remove(OPPOSING_COLOR(turn), PAWN, getEnPassantLocation(from, to));
		} else if (specialMove == PAWN_DOUBLE) {
			currentState->enPassantTarget = getEnPassantLocation(to, from);
		} 

		if (piecesIndex[to]) {
			currentState->capturedPiece = piecesIndex[to];
			currentState->capturedPieceColor = colorsIndex[to];
		} 

		if (specialMove == PROMOTION) {
			put(color, specialMovePiece, to);
		} else {
			put(color, piece, to);			
		}

		if (from == 0) {
			currentState->blackCanCastleLeft = false;
		} else if (from == 7) {
			currentState->blackCanCastleRight = false;
		} else if (from == 112) {
			currentState->whiteCanCastleLeft = false;
		} else if (from == 119) {
			currentState->whiteCanCastleRight = false;
		} else if (from == 116) {
			currentState->whiteCanCastleLeft = false;
			currentState->whiteCanCastleRight = false;
		} else if (from == 4) {
			currentState->blackCanCastleLeft = false;
			currentState->blackCanCastleRight = false;
		}

		remove(color, piece, from);
	}

	void Board::undoMove() {
		uint32_t move = currentState->move;
		uint32_t from = FROM(move);
		uint32_t to = TO(move);
		uint32_t specialMove = SPECIAL_MOVE(move);
		uint32_t specialMovePiece = PIECE(move);
		uint32_t piece = piecesIndex[to];
		uint32_t color = colorsIndex[to];


		if (specialMove == PROMOTION) {
			put(color, PAWN, from);
			remove(color, specialMovePiece, to);
		} else {
			put(color, piece, from);
			remove(color, piece, to);
		}

		if (currentState->capturedPiece) {
			put(currentState->capturedPieceColor, currentState->capturedPiece, to);
		} else if (specialMove == EN_PASSANT) {
			put(OPPOSING_COLOR(turn), PAWN, getEnPassantLocation(from, to));
		}

		decreaseStateDepth();
	}

	void Board::reset() {
		while(currentState) {
			decreaseStateDepth();
		}
		currentState = new State();
		for (int i = 0; i < BOARD_SIZE; i++) {
			piecesIndex[i] = EMPTY_SPACE;
			colorsIndex[i] = BLANK;
		}
		for (int i = 0; i < 3; i++) {
			colors[i] = 0;
		}
		for (int i = 0; i < 8; i++) {
			pieces[i] = 0;
		}
		occupiedSquares = 0;
	}

	void Board::put(uint32_t color, uint32_t piece, uint32_t location) {
		uint64_t pieceBoard = getPieceBoard(location);
		occupiedSquares |= pieceBoard;
		colors[color] |= pieceBoard;
		pieces[piece] |= pieceBoard;
		piecesIndex[location] = piece;
		colorsIndex[location] = color;
	}

	void Board::remove(uint32_t color, uint32_t piece, uint32_t location) {
		uint64_t pieceBoard = ~getPieceBoard(location);
		occupiedSquares &= pieceBoard;
		colors[color] &= pieceBoard;
		pieces[piece] &= pieceBoard;
		piecesIndex[location] = EMPTY_SPACE;
		colorsIndex[location] = BLANK;
	}
#endif