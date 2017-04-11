#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		movesPlayed.resize(MAX_MOVES_PLAYED);
		reset();
	}

	Board::~Board() {
	}

	int Board::squares[BOARD_SIZE] = {};
	int Board::pieceValue = 0;
	int Board::piecesValue[13] = {0,-1,-3,-3,-5,-9,-5,1,3,3,5,9,5};
	int Board::turn = WHITE;

	void Board::reset() {
		initializeEmptyBoard();
		enPassantTarget = SOMEWHERE_OFF_BOARD;
		fullMoveClock = 0;
		halfMoveClock = 0;
		whiteCanCastleLeft = initialWhiteCanCastleLeft;
		whiteCanCastleRight = initialWhiteCanCastleRight;
		blackCanCastleLeft = initialBlackCanCastleLeft;
		blackCanCastleRight = initialBlackCanCastleRight;
	}

	void Board::initializeEmptyBoard() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			squares[i] = EMPTY_SPACE;
		}
	}

	void Board::place(int piece, int to) {
		squares[to] = piece;
		if (piece == BLACK_KING) {
			blackKingLocation = to;
		} 
		if (piece == WHITE_KING) {
			whiteKingLocation = to;
		}
	}

	int Board::getLocation(int location) {
		if (!ON_BOARD(location)) {
			return EMPTY_SPACE;
		}

		return squares[location];
	}

	void Board::remove(int location) {
		squares[location] = EMPTY_SPACE;
	}

	void Board::doMove(uint32_t move) {
		changeTurn();
		int from = FROM(move);
		int to = TO(move);
		int captured = CAPTURED_PIECE(move);
		if (captured) {
			pieceValue -= piecesValue[captured];
		}
		place(squares[from], to);
		remove(from);
		checkAndPerformEnPassant(move);
		checkAndPerformCastle(move);
		checkAndPerformPromotion(move);
		adjustCastlingBooleansFrom(move);
		adjustCastlingBooleansTo(move);
		movesPlayed.push_back(move);
		checkAndSetEnPassantTarget();
	}


	void Board::checkAndUndoEnPassant(uint32_t move) {
		if (EN_PASSANT(move)) {
			int to = TO(move);
			int direction = GET_OPPOSING_DIRECTION(turn);
			int pawnPosition = ROWS(direction) + to;
			int pawn = turn == WHITE ? BLACK_PAWN : WHITE_PAWN;
			pieceValue += piecesValue[pawn];
			squares[pawnPosition] = pawn;
		}
	}

	void Board::checkAndSetEnPassantTarget() {
		uint32_t lastMove = movesPlayed.back();
		int to = TO(lastMove);
		int pieceMoved = squares[to];
		if (!lastMove) {
			enPassantTarget = initialEnPassantTarget;
		} else if (shouldSetEnPassantTarget(lastMove)) {
			enPassantTarget = TO(lastMove) + ROWS(GET_OPPOSING_DIRECTION(GET_COLOR(pieceMoved)));
		} else {
			enPassantTarget = SOMEWHERE_OFF_BOARD;
		}
	}

	bool Board::shouldSetEnPassantTarget(uint32_t move) {
		int to = TO(move);
		int from = FROM(move);
		int pieceMoved = squares[to];
		return (pieceMoved == BLACK_PAWN
			|| pieceMoved == WHITE_PAWN)
			&& (abs(GET_ROW(from) - GET_ROW(to)) == 2);
	}

	void Board::undoMove() {
		uint32_t move = movesPlayed.back();
		movesPlayed.pop_back();
		changeTurn();
		int from = FROM(move);
		int to = TO(move);
		int captured = CAPTURED_PIECE(move);
		if (captured) {
			pieceValue += piecesValue[captured];
		}
		place(squares[to], from);
		squares[to] = captured;
		checkAndUndoEnPassant(move);
		checkAndUndoCastle(move);
		resetCastlingBooleans(move);
		checkAndUndoPromotion(move);
		checkAndSetEnPassantTarget();
	}


	void Board::checkAndPerformEnPassant(uint32_t move) {
		if (EN_PASSANT(move)) {
			int to = TO(move);
			int direction = GET_OPPOSING_DIRECTION(GET_COLOR(squares[to]));
			int enPassantSquare = to + ROWS(direction);
			pieceValue -= piecesValue[squares[enPassantSquare]];
			remove(enPassantSquare);
		}
	}


	void Board::checkAndPerformPromotion(uint32_t move) {
		int promotedPiece = PROMOTEDPIECE(move);
		if (promotedPiece) {
			int pieceLocation = TO(move);
			pieceValue += piecesValue[promotedPiece];
			pieceValue -= piecesValue[squares[pieceLocation]];
			place(promotedPiece, pieceLocation);
		}
	}



	void Board::adjustCastlingBooleansFrom(uint32_t move) {
		switch(FROM(move)) {
			case BLACK_ROOK_RIGHT:
				blackCanCastleRight = false;
			break;
			case BLACK_ROOK_LEFT:
				blackCanCastleLeft = false;
			break;
			case BLACK_KING_POS:
				blackCanCastleRight = false;
				blackCanCastleLeft = false;
			break;
			case WHITE_ROOK_RIGHT:
				whiteCanCastleRight = false;
			break;
			case WHITE_ROOK_LEFT:
				whiteCanCastleLeft = false;
			break;
			case WHITE_KING_POS:
				whiteCanCastleLeft = false;
				whiteCanCastleRight = false;
			break;
		}
	}


	void Board::resetCastlingBooleans(uint32_t move) {
		if (move) {
			blackCanCastleRight = BLACK_CASTLE_RIGHT_FLAG(move);
			blackCanCastleLeft = BLACK_CASTLE_LEFT_FLAG(move);
			whiteCanCastleRight = WHITE_CASTLE_RIGHT_FLAG(move);
			whiteCanCastleLeft = WHITE_CASTLE_LEFT_FLAG(move);
		} else {
			blackCanCastleRight = initialBlackCanCastleRight;
			blackCanCastleLeft = initialBlackCanCastleLeft;
			whiteCanCastleRight = initialWhiteCanCastleRight;
			whiteCanCastleLeft = initialWhiteCanCastleLeft;
		}
	}

	void Board::checkAndPerformCastle(uint32_t move) {
		if (CASTLE(move)) {
			int to = TO(move);
			switch(to) {
				case BLACK_KING_CASTLE_LEFT:
					blackCanCastleRight = false;
					blackCanCastleLeft = false;
					remove(BLACK_ROOK_LEFT);
					place(BLACK_ROOK, BLACK_ROOK_CASTLE_LEFT);
				break;
				case BLACK_KING_CASTLE_RIGHT:
					blackCanCastleRight = false;
					blackCanCastleLeft = false;
					remove(BLACK_ROOK_RIGHT);
					place(BLACK_ROOK, BLACK_ROOK_CASTLE_RIGHT);
				break;
				case WHITE_KING_CASTLE_LEFT:
					whiteCanCastleRight = false;
					whiteCanCastleLeft = false;
					remove(WHITE_ROOK_LEFT);
					place(WHITE_ROOK, WHITE_ROOK_CASTLE_LEFT);
				break;
				case WHITE_KING_CASTLE_RIGHT:
					whiteCanCastleRight = false;
					whiteCanCastleLeft = false;
					remove(WHITE_ROOK_RIGHT);
					place(WHITE_ROOK, WHITE_ROOK_CASTLE_RIGHT);
				break;
			}
		}
	}

	void Board::adjustCastlingBooleansTo(uint32_t move) {
		switch(TO(move)) {
			case BLACK_ROOK_LEFT:
				blackCanCastleLeft = false;
			break;
			case BLACK_ROOK_RIGHT:
				blackCanCastleRight = false;
			break;
			case WHITE_ROOK_LEFT:
				whiteCanCastleLeft = false;
			break;
			case WHITE_ROOK_RIGHT:
				whiteCanCastleRight = false;
			break;
		}
	}

	void Board::checkAndUndoCastle(uint32_t move) {
		if (CASTLE(move)) {
			int to = TO(move);
			switch(to) {
				case BLACK_KING_CASTLE_LEFT:
					remove(BLACK_ROOK_CASTLE_LEFT);
					place(BLACK_ROOK, BLACK_ROOK_LEFT);
				break;
				case BLACK_KING_CASTLE_RIGHT:
					remove(BLACK_ROOK_CASTLE_RIGHT);
					place(BLACK_ROOK, BLACK_ROOK_RIGHT);
				break;
				case WHITE_KING_CASTLE_LEFT:
					remove(WHITE_ROOK_CASTLE_LEFT);
					place(WHITE_ROOK, WHITE_ROOK_LEFT);
				break;
				case WHITE_KING_CASTLE_RIGHT:
					remove(WHITE_ROOK_CASTLE_RIGHT);
					place(WHITE_ROOK, WHITE_ROOK_RIGHT);
				break;
			}
		}
	}


	void Board::checkAndUndoPromotion(uint32_t move) {
		int promotedPiece = PROMOTEDPIECE(move);
		if (promotedPiece) {
			int color = GET_COLOR(promotedPiece);
			int pawn = color == WHITE ? WHITE_PAWN : BLACK_PAWN;
			pieceValue += piecesValue[pawn];
			pieceValue -= piecesValue[promotedPiece];
			place(pawn, FROM(move));
		}
	}


	void Board::changeTurn() {
		turn = GET_OPPOSING_COLOR(turn);
	}
#endif