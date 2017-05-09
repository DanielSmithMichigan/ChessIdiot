	#include "Utility.h"

	UtilityTest::UtilityTest() {
	}

	UtilityTest::~UtilityTest() {
	}

	TEST_F(UtilityTest, SlideMoveGenerationUp) {
		uint64_t slideMove = generateSlideMove(0, 56, 0, -1);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			10000000,
			10000000,
			10000000,
			10000000,
			10000000,
			10000000,
			10000000,
			00000000
		));
	}

	TEST_F(UtilityTest, SlideMoveGenerationUpEmpty) {
		uint64_t slideMove = generateSlideMove(0, 0, 0, -1);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
	}

	TEST_F(UtilityTest, SlideMoveGenerationDown) {
		uint64_t slideMove = generateSlideMove(0, 0, 0, 1);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			00000000,
			10000000,
			10000000,
			10000000,
			10000000,
			10000000,
			10000000,
			10000000
		));
	}

	TEST_F(UtilityTest, SlideMoveGenerationRight) {
		uint64_t slideMove = generateSlideMove(0, 0, 1, 0);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			 1111111,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
	}

	TEST_F(UtilityTest, SlideMoveGenerationLeft) {
		uint64_t slideMove = generateSlideMove(0, 7, -1, 0);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			11111110,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
	}

	TEST_F(UtilityTest, OneBlocker) {
		uint64_t blockers = bitBoardFromRows(
			 1000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		);
		uint64_t slideMove = generateSlideMove(blockers, 0, 1, 0);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			 1000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
	}

	TEST_F(UtilityTest, TwoBlockers) {
		uint64_t blockers = bitBoardFromRows(
			 1001000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		);
		uint64_t slideMove = generateSlideMove(blockers, 0, 1, 0);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			 1000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000,
			00000000
		));
	}

	TEST_F(UtilityTest, DiagonalOne) {
		uint64_t slideMove = generateSlideMove(0, 8, 1, 1);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			00000000,
			00000000,
			 1000000,
			  100000,
			   10000,
			    1000,
			     100,
			      10
		));
	}

	TEST_F(UtilityTest, DiagonalTwo) {
		uint64_t slideMove = generateSlideMove(0, 1, 1, 1);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			00000000,
			  100000,
			   10000,
			    1000,
			     100,
			      10,
			       1,
			00000000
		));
	}

	TEST_F(UtilityTest, DiagonalThree) {
		uint64_t slideMove = generateSlideMove(0, 6, -1, 1);
		ASSERT_EQ(slideMove, bitBoardFromRows(
			00000000,
			     100,
			    1000,
			   10000,
			  100000,
			 1000000,
			10000000,
			00000000
		));
	}


	TEST_F(UtilityTest, ABC) {
		uint64_t output = binToDec(1111111);
		ASSERT_EQ(output, 127);
	}