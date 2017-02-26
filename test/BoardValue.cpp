	#include "BoardValue.h"

	BoardValueTest::BoardValueTest() {
		board.reset(new Board());
		attackedSquare.reset(new AttackedSquare(board));
		boardValue.reset(new BoardValue(board, attackedSquare));
	}

	BoardValueTest::~BoardValueTest() {
	}

	TEST_F(BoardValueTest, KingsWorthNothingBlack) {
		board->place(BLACK_KING, 0 + ROWS(0));
		ASSERT_EQ(boardValue->get(true), 0);
	}

	TEST_F(BoardValueTest, KingsWorthNothingWhite) {
		board->place(WHITE_KING, 0 + ROWS(0));	
		ASSERT_EQ(boardValue->get(true), 0);
	}

	TEST_F(BoardValueTest, WhitePawnWorthOne) {
		board->place(WHITE_PAWN, 0 + ROWS(0));	
		ASSERT_EQ(boardValue->get(true), 1);
	}

	TEST_F(BoardValueTest, WhitePawnWorthMinusOne) {
		board->place(BLACK_PAWN, 0 + ROWS(0));	
		ASSERT_EQ(boardValue->get(true), -1);
	}

	TEST_F(BoardValueTest, WillSumPieceValue) {
		board->place(WHITE_PAWN, 0 + ROWS(0));	
		board->place(BLACK_PAWN, 1 + ROWS(0));	
		ASSERT_EQ(boardValue->get(true), 0);
	}

	TEST_F(BoardValueTest, WillSumPieceValueIneven) {
		board->place(WHITE_PAWN, 0 + ROWS(0));	
		board->place(BLACK_BISHOP, 1 + ROWS(0));	
		ASSERT_EQ(boardValue->get(true), -2);
	}

	TEST_F(BoardValueTest, WillReturnStalemate) {
		board->place(BLACK_KING, 0 + ROWS(0));
		board->place(WHITE_PAWN, 2 + ROWS(2));
		board->place(WHITE_KING, 0 + ROWS(5));
		ASSERT_EQ(boardValue->get(false), STALEMATE);
	}

	TEST_F(BoardValueTest, WillReturnCheckmateBlack) {
		board->changeTurn();
		board->place(BLACK_KING, 0 + ROWS(0));
		board->place(WHITE_ROOK, 0 + ROWS(2));
		board->place(WHITE_KING, 0 + ROWS(5));
		ASSERT_EQ(boardValue->get(false), CHECKMATE);
	}

	TEST_F(BoardValueTest, WillReturnCheckmateWhite) {
		board->place(BLACK_KING, 0 + ROWS(0));
		board->place(BLACK_ROOK, 0 + ROWS(2));
		board->place(WHITE_KING, 0 + ROWS(5));
		ASSERT_EQ(boardValue->get(false), -CHECKMATE);
	}

	// It is whites turn.
	// attackedBy not passing in -> Use board->turn as color
	// color == WHITE. Use white king location.
	// Check if white king is in check.

	// If white king is in check, and we have no legal moves, then it is checkmate.