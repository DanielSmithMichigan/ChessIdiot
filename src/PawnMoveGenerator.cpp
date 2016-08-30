#ifndef PawnMoveGenerator_cpp
#define PawnMoveGenerator_cpp
	#include "PawnMoveGenerator.h"

	PawnMoveGenerator::PawnMoveGenerator(shared_ptr<Board> board, shared_ptr<MoveStack> moveStack) 
		: MoveGenerator(board, moveStack) {
	}

	PawnMoveGenerator::~PawnMoveGenerator() {
	}

	// Yes this function is pretty big, but since this is move generation, I want to save function calls.
	void PawnMoveGenerator::generateMoves(int from) {
		// Move Forward
		int oneSquareUp = from + ROWS(1);
		if (board->squares[oneSquareUp] == EMPTY_SPACE
			&& ON_BOARD(board->squares[oneSquareUp])) {
			generateMove(from, oneSquareUp);

			// Move Forward Twice
			int twoSquaresUp = from + ROWS(2);
			if (board->firstMove[from]
				&& board->squares[twoSquaresUp] == EMPTY_SPACE) {
				generateMove(from, twoSquaresUp);
			}
		}

		// Attack Right
		int thisPawn = board->squares[from];
		int attackRight = from + 1 + ROWS(1);
		int squareAttackedRight = board->squares[attackRight];
		if ((squareAttackedRight != EMPTY_SPACE
				&& GET_COLOR(thisPawn) != GET_COLOR(squareAttackedRight))
			|| 
			// En Passant
			(squareAttackedRight != EMPTY_SPACE
				&& GET_COLOR(thisPawn) != GET_COLOR(squareAttackedRight)
				&& IS_PAWN(squareAttackedRight))) {
			generateMove(from, attackRight);
		}

		// Attack Left
		int attackLeft = from - 1 + ROWS(1);
		int squareAttackedLeft = board->squares[attackLeft];
		if ((squareAttackedLeft != EMPTY_SPACE
				&& GET_COLOR(thisPawn) != GET_COLOR(squareAttackedLeft))
			|| 
			// En Passant
			(squareAttackedLeft != EMPTY_SPACE
				&& GET_COLOR(thisPawn) != GET_COLOR(squareAttackedLeft)
				&& IS_PAWN(squareAttackedLeft))) {
			generateMove(from, attackLeft);
		}
	}
#endif