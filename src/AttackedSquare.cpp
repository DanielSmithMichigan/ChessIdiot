#ifndef AttackedSquare_cpp
#define AttackedSquare_cpp
	#include "AttackedSquare.h"

	AttackedSquare::AttackedSquare(shared_ptr<Board> board) :
		board(board) {
	}

	AttackedSquare::~AttackedSquare() {

	}

	bool AttackedSquare::check(int location) {
		int attackingBishop = board->turn == WHITE ? WHITE_BISHOP : BLACK_BISHOP;
		int attackingRook = board->turn == WHITE ? WHITE_ROOK : BLACK_ROOK;
		return attackedByKnight(location)
			|| attackedByPawn(location)
			|| attackedByKing(location)
			|| attackedBySlidingPiece(location, NORTH, attackingRook)
			|| attackedBySlidingPiece(location, NORTH_EAST, attackingBishop)
			|| attackedBySlidingPiece(location, EAST, attackingRook)
			|| attackedBySlidingPiece(location, SOUTH_EAST, attackingBishop)
			|| attackedBySlidingPiece(location, SOUTH, attackingRook)
			|| attackedBySlidingPiece(location, SOUTH_WEST, attackingBishop)
			|| attackedBySlidingPiece(location, WEST, attackingRook)
			|| attackedBySlidingPiece(location, NORTH_WEST, attackingBishop);
	}

	bool AttackedSquare::attackedByPawn(int location) {
		int attackingPawn = board->turn == WHITE ? WHITE_PAWN : BLACK_PAWN;
		int attackMove1 = ROWS(GET_OPPOSING_DIRECTION(board->turn)) + 1 + location;
		int attackMove2 = ROWS(GET_OPPOSING_DIRECTION(board->turn)) - 1 + location;
		return board->squares[attackMove1] == attackingPawn
			|| board->squares[attackMove2] == attackingPawn;
	}

	bool AttackedSquare::attackedByKnight(int location) {
		int attackingKnight = board->turn == WHITE ? WHITE_KNIGHT : BLACK_KNIGHT;
		for (int i = 0; i < 8; i++) {
			if (board->squares[knightMoves[i] + location] == attackingKnight) {
				return true;
			}
		}
		return false;
	}

	bool AttackedSquare::attackedByKing(int location) {
		int attackingKing = board->turn == WHITE ? WHITE_KING : BLACK_KING;
		for (int i = 0; i < 8; i++) {
			if (board->squares[kingMoves[i] + location] == attackingKing) {
				return true;
			}
		}
		return false;
	}

	bool AttackedSquare::attackedBySlidingPiece(int from, int delta, int otherAttackingPiece) {
		int attackingQueen = board->turn == WHITE ? WHITE_QUEEN : BLACK_QUEEN;
		int to = from + delta;
		while (ON_BOARD(to)) {
			if (board->squares[to] == EMPTY_SPACE) {
				to += delta;
			} else if (board->squares[to] == attackingQueen || board->squares[to] == otherAttackingPiece) {
				return true;
			} else {
				return false;;
			}
		}
		return false;
	}

	bool AttackedSquare::kingInCheck(int color) {
		int kingLocation = color == WHITE ? board->blackKingLocation : board->whiteKingLocation;
		return check(kingLocation);
	}

#endif