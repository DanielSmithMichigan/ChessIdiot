	#include "AttackedSquare.h"

	AttackedSquareTest::AttackedSquareTest() {
		board.reset(new Board());
		attackedSquare.reset(new AttackedSquare(board));
	}

	AttackedSquareTest::~AttackedSquareTest() {
	}

	TEST_F(AttackedSquareTest, EastRook) {
		board->turn = WHITE;
		board->squares[51] = WHITE_ROOK;
		ASSERT_TRUE(attackedSquare->check(52));
	}

	TEST_F(AttackedSquareTest, WestRook) {
		board->turn = WHITE;
		board->squares[51] = WHITE_ROOK;
		ASSERT_TRUE(attackedSquare->check(50));
	}

	TEST_F(AttackedSquareTest, NorthRook) {
		board->turn = WHITE;
		board->squares[51] = WHITE_ROOK;
		ASSERT_TRUE(attackedSquare->check(51 + ROWS(1)));
	}

	TEST_F(AttackedSquareTest, SouthRook) {
		board->turn = WHITE;
		board->squares[51] = WHITE_ROOK;
		ASSERT_TRUE(attackedSquare->check(51 - ROWS(1)));
	}

	TEST_F(AttackedSquareTest, NorthEastBishop) {
		board->turn = WHITE;
		board->squares[51] = WHITE_BISHOP;
		ASSERT_TRUE(attackedSquare->check(51 + 1 + ROWS(1)));
	}

	TEST_F(AttackedSquareTest, SouthEastBishop) {
		board->turn = WHITE;
		board->squares[51] = WHITE_BISHOP;
		ASSERT_TRUE(attackedSquare->check(51 + 1 - ROWS(1)));
	}

	TEST_F(AttackedSquareTest, SouthWestBishop) {
		board->turn = WHITE;
		board->squares[51] = WHITE_BISHOP;
		ASSERT_TRUE(attackedSquare->check(51 - 1 - ROWS(1)));
	}

	TEST_F(AttackedSquareTest, NorthWestBishop) {
		board->turn = WHITE;
		board->squares[51] = WHITE_BISHOP;
		ASSERT_TRUE(attackedSquare->check(51 - 1 + ROWS(1)));
	}

	TEST_F(AttackedSquareTest, EastQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(52));
	}

	TEST_F(AttackedSquareTest, WestQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(50));
	}

	TEST_F(AttackedSquareTest, NorthQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(51 + ROWS(1)));
	}

	TEST_F(AttackedSquareTest, SouthQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(51 - ROWS(1)));
	}

	TEST_F(AttackedSquareTest, NorthEastQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(51 + 1 + ROWS(1)));
	}

	TEST_F(AttackedSquareTest, SouthEastQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(51 + 1 - ROWS(1)));
	}

	TEST_F(AttackedSquareTest, SouthWestQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(51 - 1 - ROWS(1)));
	}

	TEST_F(AttackedSquareTest, NorthWestQueen) {
		board->turn = WHITE;
		board->squares[51] = WHITE_QUEEN;
		ASSERT_TRUE(attackedSquare->check(51 - 1 + ROWS(1)));
	}

	TEST_F(AttackedSquareTest, KnightTest) {
		board->turn = WHITE;
		board->squares[51] = WHITE_KNIGHT;
		ASSERT_TRUE(attackedSquare->check(51 + KNIGHT_MOVE_1));
	}

	TEST_F(AttackedSquareTest, KingTest) {
		board->turn = WHITE;
		board->squares[51] = WHITE_KING;
		ASSERT_TRUE(attackedSquare->check(51 + KING_MOVE_1));
	}

	TEST_F(AttackedSquareTest, WhitePawnTestLeft) {
		board->turn = WHITE;
		board->squares[51] = WHITE_PAWN;
		ASSERT_TRUE(attackedSquare->check(51 - ROWS(1) + 1));
	}

	TEST_F(AttackedSquareTest, WhitePawnTestRight) {
		board->turn = WHITE;
		board->squares[51] = WHITE_PAWN;
		ASSERT_TRUE(attackedSquare->check(51 - ROWS(1) - 1));
	}

	TEST_F(AttackedSquareTest, BlackPawnTestLeft) {
		board->turn = BLACK;
		board->squares[51] = BLACK_PAWN;
		ASSERT_TRUE(attackedSquare->check(51 + ROWS(1) + 1));
	}

	TEST_F(AttackedSquareTest, BlackPawnTestRight) {
		board->turn = BLACK;
		board->squares[51] = BLACK_PAWN;
		ASSERT_TRUE(attackedSquare->check(51 + ROWS(1) - 1));
	}