#ifndef KingMoveGenerator_cpp
#define KingMoveGenerator_cpp
	#include "KingMoveGenerator.h"

	KingMoveGenerator::KingMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) 
		: MoveGenerator(board, moveStack, attackedSquare) {
	}

	KingMoveGenerator::~KingMoveGenerator() {
	}

	void KingMoveGenerator::generateMoves(int from) {
		generateAdjacentMoves(from);
		generateCastle(from);
	}

	void KingMoveGenerator::generateAdjacentMoves(int from) {
		for (int i = 0; i < KING_MOVES_SIZE; i++) {
			int to = kingMoves[i] + from;
			if (ON_BOARD(to) 
				&& (board->squares[to] == EMPTY_SPACE
					|| GET_COLOR(board->squares[from]) != GET_COLOR(board->squares[to]))) {
				generateMove(from, to);
			}
		}
	}

	void KingMoveGenerator::generateCastle(int from) {
		if (!board->firstMove[from]
			|| attackedSquare->kingInCheck()) {
			return;
		}
		int kingColor = GET_COLOR(board->squares[from]);
		int rookLeftPosition = kingColor == WHITE ? whiteCastleLeft : blackCastleLeft;
		int rookRightPosition = kingColor == WHITE ? whiteCastleRight : blackCastleRight;
		int rook = kingColor == WHITE ? WHITE_ROOK : BLACK_ROOK;
		if (board->firstMove[rookRightPosition]
				&& board->squares[rookRightPosition] == rook
				&& !castleSquaresOccupied(from, EAST)
				&& !castleSquaresAttacked(from, EAST)) {
			generateMove(from, from + 2, BLANK, BLANK, 1);
		}
		if (board->firstMove[rookLeftPosition]
				&& board->squares[rookLeftPosition] == rook
				&& !castleSquaresOccupied(from, WEST)
				&& !castleSquaresAttacked(from, WEST)) {
			generateMove(from, from - 2, BLANK, BLANK, 1);
		}
	}

	bool KingMoveGenerator::castleSquaresOccupied(int from, int eastWest) {
		int kingColor = GET_COLOR(board->squares[from]);
		int (&arrayOfSquares)[2] = getArrayOfSquares(from, eastWest);
		for (int i = 0; i < 2; i++) {
			int squareToCheck = arrayOfSquares[i];
			if (squareToCheck == SOMEWHERE_OFF_BOARD) {
				return false;
			} else if (board->squares[squareToCheck] != EMPTY_SPACE) {
				return true;
			}
		}
		return false;
	}

	bool KingMoveGenerator::castleSquaresAttacked(int from, int eastWest) {
		int (&arrayOfSquares)[2] = getArrayOfSquares(from, eastWest);
		for (int i = 0; i < 2; i++) {
			int squareToCheck = arrayOfSquares[i];
			if (squareToCheck == SOMEWHERE_OFF_BOARD) {
				return false;
			} else if (attackedSquare->check(squareToCheck, GET_OPPOSING_COLOR(board->turn))) {
				return true;
			}
		}
		return false;
	}

	int (&KingMoveGenerator::getArrayOfSquares(int from, int eastWest))[2] {
		return GET_COLOR(board->squares[from]) == WHITE ?
				eastWest == EAST ? whiteCastleSquaresEast : whiteCastleSquaresWest
				: eastWest == EAST ? blackCastleSquaresEast : blackCastleSquaresWest;
	}
#endif