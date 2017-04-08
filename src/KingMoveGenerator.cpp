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
		int myKingColor = GET_COLOR(board->squares[from]);
		for (int i = 0; i < KING_MOVES_SIZE; i++) {
			int to = kingMoves[i] + from;
			int pieceAtLocation = board->squares[to];
			if (ON_BOARD(to)
				&& (pieceAtLocation == EMPTY_SPACE
					|| myKingColor != GET_COLOR(pieceAtLocation))) {
				generateMove(from, to);
			}
		}
	}

	void KingMoveGenerator::generateCastle(int from) {
		if (attackedSquare->kingInCheck()) {
			return;
		}
		int kingColor = GET_COLOR(board->squares[from]);
		bool canCastleLeft = kingColor == WHITE ? board->whiteCanCastleLeft : board->blackCanCastleLeft;
		bool canCastleRight = kingColor == WHITE ? board->whiteCanCastleRight : board->blackCanCastleRight;
		if (canCastleRight
				&& !castleSquaresOccupied(from, EAST)
				&& !castleSquaresAttacked(from, EAST)) {
		    generateMove(from, from + 2, BLANK, BLANK, true);
		}
		if (canCastleLeft
				&& !castleSquaresOccupied(from, WEST)
				&& !castleSquaresAttacked(from, WEST)) {
			generateMove(from, from - 2, BLANK, BLANK, true);
		}
	}

	bool KingMoveGenerator::castleSquaresOccupied(int from, int eastWest) {
		int kingColor = GET_COLOR(board->squares[from]);
		int (&arrayOfSquares)[3] = getArrayOfOccupiedSquares(from, eastWest);
		for (int i = 0; i < 3; i++) {
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
		int (&arrayOfSquares)[2] = getArrayOfAttackedSquares(from, eastWest);
		for (int i = 0; i < 2; i++) {
			int squareToCheck = arrayOfSquares[i];
			if (attackedSquare->check(squareToCheck, GET_OPPOSING_COLOR(board->turn))) {
				return true;
			}
		}
		return false;
	}

	int (&KingMoveGenerator::getArrayOfOccupiedSquares(int from, int eastWest))[3] {
		return GET_COLOR(board->squares[from]) == WHITE ?
				eastWest == EAST ? whiteCastleSquaresOccupiedEast : whiteCastleSquaresOccupiedWest
				: eastWest == EAST ? blackCastleSquaresOccupiedEast : blackCastleSquaresOccupiedWest;
	}

	int (&KingMoveGenerator::getArrayOfAttackedSquares(int from, int eastWest))[2] {
		return GET_COLOR(board->squares[from]) == WHITE ?
				eastWest == EAST ? whiteCastleSquaresAttackedEast : whiteCastleSquaresAttackedWest
				: eastWest == EAST ? blackCastleSquaresAttackedEast : blackCastleSquaresAttackedWest;
	}
#endif