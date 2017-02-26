#ifndef PawnMoveGenerator_cpp
#define PawnMoveGenerator_cpp
	#include "PawnMoveGenerator.h"

	PawnMoveGenerator::PawnMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack, shared_ptr<AttackedSquare> attackedSquare) 
		: MoveGenerator(board, moveStack, attackedSquare) {
	}

	PawnMoveGenerator::~PawnMoveGenerator() {
	}

	// Yes this function is pretty big, but since this is move generation, I want to save function calls.
	void PawnMoveGenerator::generateMoves(int from) {
		int thisPawn = board->getLocation(from);
		int thisPawnColor = GET_COLOR(thisPawn);

		// Move Forward
		int oneSquareUp = from + ROWS(direction);
		if (board->getLocation(oneSquareUp) == EMPTY_SPACE
			&& ON_BOARD(oneSquareUp)) {
			testAndGenerateMove(from, oneSquareUp, thisPawn);

			// Move Forward Twice
			int twoSquaresUp = from + ROWS(2 * direction);
			int doubleMoveRow = thisPawnColor == WHITE ? 6 : 1;
			if (GET_ROW(from) == doubleMoveRow
				&& board->getLocation(twoSquaresUp) == EMPTY_SPACE) {
				generateMove(from, twoSquaresUp);
			}
		}

		// Attack Right
		int attackRight = from + 1 + ROWS(direction);
		int squareAttackedRight = board->getLocation(attackRight);
		if (squareAttackedRight != EMPTY_SPACE
				&& thisPawnColor != GET_COLOR(squareAttackedRight)) {
			testAndGenerateMove(from, attackRight, thisPawn);
		}


		// En Passant Right
		int enPassantRight = from + 1;
		int squareEnPassantRight = board->getLocation(enPassantRight);
		if (squareEnPassantRight != EMPTY_SPACE
				&& thisPawnColor != GET_COLOR(squareEnPassantRight)
					&& board->enPassantTarget == attackRight) {
			generateMove(from, attackRight, BLANK, 1);
		}

		// Attack Left
		int attackLeft = from - 1 + ROWS(direction);
		int squareAttackedLeft = board->getLocation(attackLeft);
		if (squareAttackedLeft != EMPTY_SPACE
				&& thisPawnColor != GET_COLOR(squareAttackedLeft)) {
			testAndGenerateMove(from, attackLeft, thisPawn);
		}


		// En Passant Left
		int enPassantLeft = from - 1;
		int squareEnPassantLeft = board->getLocation(enPassantLeft);
		if (squareEnPassantLeft != EMPTY_SPACE
				&& thisPawnColor != GET_COLOR(squareEnPassantLeft)
					&& board->enPassantTarget == attackLeft) {
			generateMove(from, attackLeft, BLANK, 1);
		}
	}

	void PawnMoveGenerator::testAndGenerateMove(int from, int to, int piece) {
		if (FIRST_RANK(to) || LAST_RANK(to)) {
			if (piece == BLACK_PAWN) {
				generateMove(from, to, BLACK_KNIGHT);
				generateMove(from, to, BLACK_BISHOP);
				generateMove(from, to, BLACK_QUEEN);
				generateMove(from, to, BLACK_ROOK);
			} else {
				generateMove(from, to, WHITE_KNIGHT);
				generateMove(from, to, WHITE_BISHOP);
				generateMove(from, to, WHITE_QUEEN);
				generateMove(from, to, WHITE_ROOK);
			}
		} else {
			generateMove(from, to);
		}
	}
#endif