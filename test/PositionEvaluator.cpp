	#include "PositionEvaluator.h"

	PositionEvaluatorTest::PositionEvaluatorTest() {
		board.reset(new Board());
		attackedSquare.reset(new AttackedSquare(board));
		positionEvaluator.reset(new PositionEvaluator(board, attackedSquare));
	}

	PositionEvaluatorTest::~PositionEvaluatorTest() {
	}

	TEST_F(PositionEvaluatorTest, KingsWorthNothingBlack) {
		board->place(BLACK_KING, 0 + ROWS(0));
		ASSERT_EQ(positionEvaluator->piecesValue(), 0);
	}

	TEST_F(PositionEvaluatorTest, KingsWorthNothingWhite) {
		board->place(WHITE_KING, 0 + ROWS(0));	
		ASSERT_EQ(positionEvaluator->piecesValue(), 0);
	}

	TEST_F(PositionEvaluatorTest, WhitePawnWorthOne) {
		board->place(WHITE_PAWN, 0 + ROWS(0));	
		ASSERT_EQ(positionEvaluator->piecesValue(), -1);
	}

	TEST_F(PositionEvaluatorTest, WhitePawnWorthMinusOne) {
		board->place(BLACK_PAWN, 0 + ROWS(0));	
		ASSERT_EQ(positionEvaluator->piecesValue(), 1);
	}

	TEST_F(PositionEvaluatorTest, WillSumPieceValue) {
		board->place(WHITE_PAWN, 0 + ROWS(0));	
		board->place(BLACK_PAWN, 1 + ROWS(0));	
		ASSERT_EQ(positionEvaluator->piecesValue(), 0);
	}

	TEST_F(PositionEvaluatorTest, WillSumPieceValueIneven) {
		board->place(WHITE_PAWN, 0 + ROWS(0));	
		board->place(BLACK_BISHOP, 1 + ROWS(0));	
		ASSERT_EQ(positionEvaluator->piecesValue(), 2);
	}

	TEST_F(PositionEvaluatorTest, WillReturnStalemate) {
		board->place(BLACK_KING, 0 + ROWS(0));
		board->place(WHITE_PAWN, 2 + ROWS(2));
		board->place(WHITE_KING, 0 + ROWS(5));
		ASSERT_EQ(positionEvaluator->terminalPositionValue(), STALEMATE);
	}

	TEST_F(PositionEvaluatorTest, WillReturnCheckmateBlack) {
		board->changeTurn();
		board->place(BLACK_KING, 0 + ROWS(0));
		board->place(WHITE_ROOK, 0 + ROWS(2));
		board->place(WHITE_KING, 0 + ROWS(5));
		ASSERT_EQ(positionEvaluator->terminalPositionValue(), -CHECKMATE);
	}

	TEST_F(PositionEvaluatorTest, WillReturnCheckmateWhite) {
		board->place(BLACK_KING, 0 + ROWS(0));
		board->place(BLACK_ROOK, 0 + ROWS(2));
		board->place(WHITE_KING, 0 + ROWS(5));
		ASSERT_EQ(positionEvaluator->terminalPositionValue(), CHECKMATE);
	}