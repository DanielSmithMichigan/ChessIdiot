#ifndef Board_cpp
#define Board_cpp
	#include "Board.h"

	Board::Board() {
		movesPlayed.resize(MAX_MOVES_PLAYED);
		empty();
	}

	Board::~Board() {
	}

	void Board::empty() {
		initializeEmptyBoard();
		initializeFirstMove();
		turn = WHITE;
		initialEnPassantTarget = SOMEWHERE_OFF_BOARD;
		enPassantTarget = SOMEWHERE_OFF_BOARD;
		fullMoveClock = 0;
		halfMoveClock = 0;
	}

	void Board::initializeEmptyBoard() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			squares[i] = EMPTY_SPACE;
		}
	}

	void Board::initializeFirstMove() {
		for (int i = 0; i < BOARD_SIZE; i++) {
			firstMove[i] = true;
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

	void Board::remove(int location) {
		squares[location] = EMPTY_SPACE;
	}

	void Board::undoMove() {
		uint32_t move = movesPlayed.back();
		movesPlayed.pop_back();
		changeTurn();
		int from = FROM(move);
		int to = TO(move);
		firstMove[from] = FIRST_MOVE(move);
		place(squares[to], from);
		// We need to properly set first move of the captured piece.
		squares[to] = CAPTURED_PIECE(move);
		checkAndUndoEnPassant(move);
		checkAndUndoCastle(move);
		checkAndSetEnPassantTarget();
	}

	void Board::checkAndUndoEnPassant(uint32_t move) {
		if (EN_PASSANT(move)) {
			int to = TO(move);
			int direction = GET_OPPOSING_DIRECTION(turn);
			int pawnPosition = ROWS(direction) + to;
			squares[pawnPosition] = turn == WHITE ? BLACK_PAWN : WHITE_PAWN;
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

	void Board::doMove(uint32_t move) {
		changeTurn();
		int from = FROM(move);
		int to = TO(move);
		place(squares[from], to);
		remove(from);
		checkAndPerformEnPassant(move);
		checkAndPerformCastle(move);
		firstMove[to] = 0;
		movesPlayed.push_back(move);
		checkAndSetEnPassantTarget();
	}

	void Board::checkAndPerformEnPassant(uint32_t move) {
		if (EN_PASSANT(move)) {
			int to = TO(move);
			int direction = GET_OPPOSING_DIRECTION(GET_COLOR(squares[to]));
			int enPassantSquare = to + ROWS(direction);
			remove(enPassantSquare);
		}
	}

	void Board::checkAndPerformCastle(uint32_t move) {
		if (CASTLE(move)) {
			int to = TO(move);
			switch(to) {
				case BLACK_KING_CASTLE_LEFT:
					firstMove[BLACK_ROOK_CASTLE_LEFT] = false;
					place(BLACK_ROOK, BLACK_ROOK_CASTLE_LEFT);
					remove(BLACK_ROOK_LEFT);
				break;
				case BLACK_KING_CASTLE_RIGHT:
					firstMove[BLACK_ROOK_CASTLE_RIGHT] = false;
					place(BLACK_ROOK, BLACK_ROOK_CASTLE_RIGHT);
					remove(BLACK_ROOK_RIGHT);
				break;
				case WHITE_KING_CASTLE_LEFT:
					firstMove[WHITE_ROOK_CASTLE_LEFT] = false;
					place(WHITE_ROOK, WHITE_ROOK_CASTLE_LEFT);
					remove(WHITE_ROOK_LEFT);
				break;
				case WHITE_KING_CASTLE_RIGHT:
					firstMove[WHITE_ROOK_CASTLE_RIGHT] = false;
					place(WHITE_ROOK, WHITE_ROOK_CASTLE_RIGHT);
					remove(WHITE_ROOK_RIGHT);
				break;
			}
		}
	}

	void Board::checkAndUndoCastle(uint32_t move) {
		if (CASTLE(move)) {
			int to = TO(move);
			switch(to) {
				case BLACK_KING_CASTLE_LEFT:
					firstMove[BLACK_ROOK_LEFT] = true;
					place(BLACK_ROOK, BLACK_ROOK_LEFT);
					remove(BLACK_ROOK_CASTLE_LEFT);
				break;
				case BLACK_KING_CASTLE_RIGHT:
					firstMove[BLACK_ROOK_RIGHT] = true;
					place(BLACK_ROOK, BLACK_ROOK_RIGHT);
					remove(BLACK_ROOK_CASTLE_RIGHT);
				break;
				case WHITE_KING_CASTLE_LEFT:
					firstMove[WHITE_ROOK_LEFT] = true;
					place(WHITE_ROOK, WHITE_ROOK_LEFT);
					remove(WHITE_ROOK_CASTLE_LEFT);
				break;
				case WHITE_KING_CASTLE_RIGHT:
					firstMove[WHITE_ROOK_RIGHT] = true;
					place(WHITE_ROOK, WHITE_ROOK_RIGHT);
					remove(WHITE_ROOK_CASTLE_RIGHT);
				break;
			}
		}
	}


	void Board::changeTurn() {
		turn = GET_OPPOSING_COLOR(turn);
	}
#endif