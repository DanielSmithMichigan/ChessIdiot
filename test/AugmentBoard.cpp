	#include "AugmentBoard.h"

	AugmentBoardTest::AugmentBoardTest() {
		Init::instance->execute(true);
	}

	AugmentBoardTest::~AugmentBoardTest() {
	}

	void AugmentBoardTest::SetUp() {
		Board::reset();
	}

	TEST_F(AugmentBoardTest, OnePinnedKnight) {
		Fen* fen = new Fen();
		fen->import("k7/1n6/8/8/8/8/6Q1/7K b");
		ASSERT_EQ(Board::currentState->pinnedToKing[BLACK], bitBoardFromRows(
			00000000,
			 1000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
		ASSERT_EQ(Board::currentState->pinners[BLACK], bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			      10,
			00000000
		));
		ASSERT_EQ(Board::currentState->pinnedToKing[WHITE], 0);
		ASSERT_EQ(Board::currentState->pinners[WHITE], 0);
	}

	TEST_F(AugmentBoardTest, TwoPinnedKnights) {
		Fen* fen = new Fen();
		fen->import("k7/1n6/2n5/8/8/8/6Q1/7K b");
		ASSERT_EQ(Board::currentState->pinnedToKing[BLACK], 0);
		ASSERT_EQ(Board::currentState->pinnedToKing[WHITE], 0);
		ASSERT_EQ(Board::currentState->pinners[BLACK], 0);
		ASSERT_EQ(Board::currentState->pinners[WHITE], 0);
	}

	TEST_F(AugmentBoardTest, OneNotPinnedKnight) {
		Fen* fen = new Fen();
		fen->import("8/8/2kn2Q1/8/8/8/8/7K b");
		ASSERT_EQ(Board::currentState->pinnedToKing[BLACK], bitBoardFromRows(
			00000000,
			00000000,
			   10000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
		ASSERT_EQ(Board::currentState->pinners[BLACK], bitBoardFromRows(
			00000000,
			00000000,
			      10,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
		ASSERT_EQ(Board::currentState->pinnedToKing[WHITE], 0);
		ASSERT_EQ(Board::currentState->pinners[WHITE], 0);
	}

	TEST_F(AugmentBoardTest, OnePinnedKnightWHITE) {
		Fen* fen = new Fen();
		fen->import("8/8/2k5/8/8/8/8/2r3BK b");
		ASSERT_EQ(Board::currentState->pinnedToKing[WHITE], bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			      10
		));
		ASSERT_EQ(Board::currentState->pinners[WHITE], bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			  100000
		));
		ASSERT_EQ(Board::currentState->pinnedToKing[BLACK], 0);
		ASSERT_EQ(Board::currentState->pinners[BLACK], 0);
	}

	TEST_F(AugmentBoardTest, OnePinnedKnightWhite) {
		Fen* fen = new Fen();
		fen->import("8/8/2k5/3b4/8/8/6N1/7K b");
		ASSERT_EQ(Board::currentState->pinners[WHITE], bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			   10000,
			00000000,
			00000000,
			00000000,
			00000000
		));
		ASSERT_EQ(Board::currentState->pinnedToKing[WHITE], bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			      10,
			00000000
		));
		ASSERT_EQ(Board::currentState->pinnedToKing[BLACK], 0);
		ASSERT_EQ(Board::currentState->pinners[BLACK], 0);
	}

	TEST_F(AugmentBoardTest, OneQueenChecker) {
		Fen* fen = new Fen();
		fen->import("k7/8/8/8/8/8/6Q1/7K b");
		ASSERT_EQ(Board::currentState->checkers, bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			      10,
			00000000
		));
		ASSERT_EQ(Board::currentState->blockingSquares, bitBoardFromRows(
			00000000,
			 1000000,
			  100000,
			   10000,
			    1000,
			     100,
			      10,
			00000000
		));
		ASSERT_EQ(Board::currentState->doubleCheck, false);
	}

