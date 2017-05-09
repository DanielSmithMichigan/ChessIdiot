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

	TEST_F(UtilityTest, ABC) {
		uint64_t output = binToDec(1111111);
		ASSERT_EQ(output, 127);
	}