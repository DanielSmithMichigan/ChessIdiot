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
	int Board::pieceValue = 0;
	int Board::PiecesValue[7] = {
		0, 100, 325, 325, 550, 1000, 100
	};

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
			remove(OPPOSING_COLOR(turn), PAWN, getEnPassantPawnLocation(from, to));
		} else if (specialMove == PAWN_DOUBLE) {
			currentState->enPassantTarget = getEnPassantTarget(from, to);
			currentState->zobrist ^= Zobrist::EnPassant[GET_COLUMN(currentState->enPassantTarget)];
		}  else if (specialMove == CASTLE) {
			if (to == 62) {
				remove(color, ROOK, 63);
				put(color, ROOK, 61);
			} else if (to == 58) {
				remove(color, ROOK, 56);
				put(color, ROOK, 59);
			} else if (to == 6) {
				remove(color, ROOK, 7);
				put(color, ROOK, 5);
			} else if (to == 2) {
				remove(color, ROOK, 0);
				put(color, ROOK, 3);
			}
		}

		if (piecesIndex[to]) {
			currentState->capturedPiece = piecesIndex[to];
			currentState->capturedPieceColor = colorsIndex[to];
			remove(colorsIndex[to], piecesIndex[to], to);
			currentState->halfMoveCount = 0;
		} 

		if (piecesIndex[from] == PAWN) {
			currentState->halfMoveCount = 0;
		}

		if (specialMove == PROMOTION) {
			put(color, specialMovePiece, to);
		} else {
			put(color, piece, to);			
		}
		
		currentState->zobrist ^= Zobrist::CastlingRights[currentState->castlingRights];

		if (to == 0) {
			currentState->castlingRights &= BLACK_CANT_CASTLE_LEFT;
		} else if (to == 7) {
			currentState->castlingRights &= BLACK_CANT_CASTLE_RIGHT;
		} else if (to == 56) {
			currentState->castlingRights &= WHITE_CANT_CASTLE_LEFT;
		} else if (to == 63) {
			currentState->castlingRights &= WHITE_CANT_CASTLE_RIGHT;
		}

		if (from == 0) {
			currentState->castlingRights &= BLACK_CANT_CASTLE_LEFT;
		} else if (from == 7) {
			currentState->castlingRights &= BLACK_CANT_CASTLE_RIGHT;
		} else if (from == 56) {
			currentState->castlingRights &= WHITE_CANT_CASTLE_LEFT;
		} else if (from == 63) {
			currentState->castlingRights &= WHITE_CANT_CASTLE_RIGHT;
		} else if (from == 60) {
			currentState->castlingRights &= WHITE_CANT_CASTLE_LEFT;
			currentState->castlingRights &= WHITE_CANT_CASTLE_RIGHT;
		} else if (from == 4) {
			currentState->castlingRights &= BLACK_CANT_CASTLE_LEFT;
			currentState->castlingRights &= BLACK_CANT_CASTLE_RIGHT;
		}
		
		currentState->zobrist ^= Zobrist::CastlingRights[currentState->castlingRights];

		remove(color, piece, from);

		Board::turn = OPPOSING_COLOR(Board::turn);
		currentState->zobrist ^= Zobrist::BlackToMove;
		augmentCurrentState();
	}

	void Board::augmentCurrentState() {
		uint64_t blackPinnedPieces = 0, blackPinners = 0;
		getPinnedPieces<BLACK, KING, ROOK>(blackPinnedPieces, blackPinners);
		getPinnedPieces<BLACK, KING, BISHOP>(blackPinnedPieces, blackPinners);
		currentState->pinnedToKing[BLACK] = blackPinnedPieces;
		currentState->pinners[BLACK] = blackPinners;

		uint64_t whitePinnedPieces = 0, whitePinners = 0;
		getPinnedPieces<WHITE, KING, ROOK>(whitePinnedPieces, whitePinners);
		getPinnedPieces<WHITE, KING, BISHOP>(whitePinnedPieces, whitePinners);
		currentState->pinnedToKing[WHITE] = whitePinnedPieces;
		currentState->pinners[WHITE] = whitePinners;

		uint64_t checkers = 0, blockingSquares = 0, attackedPieces = 0;
		if (turn == WHITE) {
			getAttackers<WHITE, KING>(attackedPieces, checkers, blockingSquares);
		} else if (turn == BLACK) {
			getAttackers<BLACK, KING>(attackedPieces, checkers, blockingSquares);
		}
		currentState->checkers = checkers;
		currentState->blockingSquares = blockingSquares;
		currentState->doubleCheck = countOnes(checkers) > 1;
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
			put(turn, PAWN, getEnPassantPawnLocation(from, to));
		} else if (specialMove == CASTLE) {
			if (to == 62) {
				put(color, ROOK, 63);
				remove(color, ROOK, 61);
			} else if (to == 58) {
				put(color, ROOK, 56);
				remove(color, ROOK, 59);
			} else if (to == 6) {
				put(color, ROOK, 7);
				remove(color, ROOK, 5);
			} else if (to == 2) {
				put(color, ROOK, 0);
				remove(color, ROOK, 3);
			}
		}

		decreaseStateDepth();
		Board::turn = OPPOSING_COLOR(Board::turn);
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
		pieceValue = 0;
	}

	void Board::put(uint32_t color, uint32_t piece, uint32_t location) {
		currentState->zobrist ^= Zobrist::PieceBySquare[color- 1][piece][location];
		uint64_t pieceBoard = getPieceBoard(location);
		occupiedSquares |= pieceBoard;
		colors[color] |= pieceBoard;
		pieces[piece] |= pieceBoard;
		piecesIndex[location] = piece;
		colorsIndex[location] = color;
		if (color == WHITE) {
			pieceValue -= Board::PiecesValue[piece];
			pieceValue -= PiecesValue::getValue<WHITE>(piece, location);
		} else {
			pieceValue += Board::PiecesValue[piece];
			pieceValue += PiecesValue::getValue<BLACK>(piece, location);
		}
	}

	void Board::remove(uint32_t color, uint32_t piece, uint32_t location) {
		currentState->zobrist ^= Zobrist::PieceBySquare[color - 1][piece][location];
		uint64_t pieceBoard = ~getPieceBoard(location);
		occupiedSquares &= pieceBoard;
		colors[color] &= pieceBoard;
		pieces[piece] &= pieceBoard;
		piecesIndex[location] = EMPTY_SPACE;
		colorsIndex[location] = BLANK;
		if (color == BLACK) {
			pieceValue -= Board::PiecesValue[piece];
			pieceValue -= PiecesValue::getValue<BLACK>(piece, location);
		} else {
			pieceValue += Board::PiecesValue[piece];
			pieceValue += PiecesValue::getValue<WHITE>(piece, location);
		}
	}
#endif