	#include "SquareAttacked.h"

	SquareAttackedTest::SquareAttackedTest() {
		Board::reset();
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	SquareAttackedTest::~SquareAttackedTest() {
	}

	void SquareAttackedTest::SetUp() {
	}

	TEST_F(SquareAttackedTest, QueenRook) {
		Fen* fen = new Fen();
		fen->import("8/2rqRQ2/8/8/8/8/8/8");
		ASSERT_TRUE(squareAttacked<WHITE>(61));
		ASSERT_TRUE(squareAttacked<WHITE>(60));
		ASSERT_TRUE(squareAttacked<BLACK>(59));
		ASSERT_TRUE(squareAttacked<BLACK>(58));
		ASSERT_TRUE(!squareAttacked<BLACK>(61));
		ASSERT_TRUE(!squareAttacked<BLACK>(60));
		ASSERT_TRUE(!squareAttacked<WHITE>(59));
		ASSERT_TRUE(!squareAttacked<WHITE>(58));
	}

	TEST_F(SquareAttackedTest, QueenBishop) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/qQ4bB/8/8/8");
		ASSERT_TRUE(squareAttacked<WHITE>(60));
		ASSERT_TRUE(squareAttacked<BLACK>(59));
		ASSERT_TRUE(!squareAttacked<BLACK>(60));
		ASSERT_TRUE(!squareAttacked<WHITE>(59));
	}

	TEST_F(SquareAttackedTest, Knight) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/8/2n2N2/8/8");
		ASSERT_TRUE(squareAttacked<WHITE>(60));
		ASSERT_TRUE(squareAttacked<BLACK>(59));
		ASSERT_TRUE(!squareAttacked<BLACK>(60));
		ASSERT_TRUE(!squareAttacked<WHITE>(59));
	}

	TEST_F(SquareAttackedTest, King) {
		Fen* fen = new Fen();
		fen->import("8/8/8/8/8/8/2k2K2/8");
		ASSERT_TRUE(squareAttacked<WHITE>(60));
		ASSERT_TRUE(squareAttacked<BLACK>(59));
		ASSERT_TRUE(!squareAttacked<BLACK>(60));
		ASSERT_TRUE(!squareAttacked<WHITE>(59));
	}

	TEST_F(SquareAttackedTest, Pawn) {
		Fen* fen = new Fen();
		fen->import("8/1P4P1/8/8/8/8/1p4p1/8");
		ASSERT_TRUE(squareAttacked<WHITE>(0));
		ASSERT_TRUE(squareAttacked<WHITE>(7));
		ASSERT_TRUE(squareAttacked<BLACK>(56));
		ASSERT_TRUE(squareAttacked<BLACK>(63));
	}

	TEST_F(SquareAttackedTest, CanTakeKing) {
		Fen* fen = new Fen();
		fen->import("rnbqkbnr/pppp2pp/4p3/5p1Q/8/4P3/PPPP1PPP/RNB1KBNR w");
		ASSERT_TRUE(canTakeKing());
	}

	TEST_F(SquareAttackedTest, CanNotTakeKing) {
		Fen* fen = new Fen();
		fen->import("rnbqkbnr/pppp2pp/4p3/5p1Q/8/4P3/PPPP1PPP/RNB1KBNR b");
		ASSERT_FALSE(canTakeKing());
	}