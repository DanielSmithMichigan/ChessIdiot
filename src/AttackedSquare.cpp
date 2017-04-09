#ifndef AttackedSquare_cpp
#define AttackedSquare_cpp
	#include "AttackedSquare.h"

	AttackedSquare::AttackedSquare(shared_ptr<Board> board) :
		board(board) {
	}

	AttackedSquare::~AttackedSquare() {

	}

	bool AttackedSquare::check(int location, int attackedBy) {
		int attackingBishop = defaultColor(attackedBy) == WHITE ? WHITE_BISHOP : BLACK_BISHOP;
		int attackingRook = defaultColor(attackedBy) == WHITE ? WHITE_ROOK : BLACK_ROOK;
		return attackedByKnight(location, attackedBy)
			|| attackedByPawn(location, attackedBy)
			|| attackedByKing(location, attackedBy)
			|| attackedBySlidingPiece(location, NORTH, attackingRook, attackedBy)
			|| attackedBySlidingPiece(location, NORTH_EAST, attackingBishop, attackedBy)
			|| attackedBySlidingPiece(location, EAST, attackingRook, attackedBy)
			|| attackedBySlidingPiece(location, SOUTH_EAST, attackingBishop, attackedBy)
			|| attackedBySlidingPiece(location, SOUTH, attackingRook, attackedBy)
			|| attackedBySlidingPiece(location, SOUTH_WEST, attackingBishop, attackedBy)
			|| attackedBySlidingPiece(location, WEST, attackingRook, attackedBy)
			|| attackedBySlidingPiece(location, NORTH_WEST, attackingBishop, attackedBy);
	}

	bool AttackedSquare::attackedByPawn(int location, int attackedBy) {
		int attackingPawn = defaultColor(attackedBy) == WHITE ? WHITE_PAWN : BLACK_PAWN;
		int attackMove1 = ROWS(GET_OPPOSING_DIRECTION(defaultColor(attackedBy))) + 1 + location;
		int attackMove2 = ROWS(GET_OPPOSING_DIRECTION(defaultColor(attackedBy))) - 1 + location;
		return Board::getLocation(attackMove1) == attackingPawn
			|| Board::getLocation(attackMove2) == attackingPawn;
	}

	bool AttackedSquare::attackedByKnight(int location, int attackedBy) {
		int attackingKnight = defaultColor(attackedBy) == WHITE ? WHITE_KNIGHT : BLACK_KNIGHT;
		for (int i = 0; i < 8; i++) {
			if (Board::getLocation(knightMoves[i] + location) == attackingKnight) {
				return true;
			}
		}
		return false;
	}

	bool AttackedSquare::attackedByKing(int location, int attackedBy) {
		int attackingKing = defaultColor(attackedBy) == WHITE ? WHITE_KING : BLACK_KING;
		for (int i = 0; i < 8; i++) {
			if (Board::getLocation(kingMoves[i] + location) == attackingKing) {
				return true;
			}
		}
		return false;
	}

	bool AttackedSquare::attackedBySlidingPiece(int from, int delta, int otherAttackingPiece, int attackedBy) {
		int attackingQueen = defaultColor(attackedBy) == WHITE ? WHITE_QUEEN : BLACK_QUEEN;
		int to = from + delta;
		while (ON_BOARD(to)) {
			int pieceAtLocation = Board::squares[to];
			if (pieceAtLocation == EMPTY_SPACE) {
				to += delta;
			} else if (pieceAtLocation == attackingQueen || pieceAtLocation == otherAttackingPiece) {
				return true;
			} else {
				return false;
			}
		}
		return false;
	}

	int AttackedSquare::defaultColor(int attackedBy) {
		return attackedBy == BLANK ? board->turn : attackedBy;
	}

	bool AttackedSquare::kingInCheck(int kingColor) {
		kingColor = defaultColor(kingColor);
		int kingLocation = kingColor == WHITE ? board->whiteKingLocation : board->blackKingLocation;
		return check(kingLocation, GET_OPPOSING_COLOR(kingColor));
	}

#endif