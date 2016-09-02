	#include "MoveGenerationController.h"

	MoveGenerationControllerTest::MoveGenerationControllerTest() {
		moveStack = make_shared<MoveStack>();
		board = make_shared<Board>();
		moveGenerationController.reset(new MoveGenerationController(board, moveStack));
	}

	MoveGenerationControllerTest::~MoveGenerationControllerTest() {
	}

	void MoveGenerationControllerTest::SetUp() {
		int newBoardArray[] = {
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		};
		copy(begin(newBoardArray), end(newBoardArray), begin(board->squares));
	}

	TEST_F(MoveGenerationControllerTest, KingInCorner) {
		board->squares[0] = WHITE_KING;
		moveGenerationController->generateMovesAt(0);
		EXPECT_EQ(moveStack->top, 3);
		sort(moveStack->stack, moveStack->stack + 3);
		EXPECT_EQ(FROM(moveStack->stack[0]), 0);
		EXPECT_EQ(FROM(moveStack->stack[1]), 0);
		EXPECT_EQ(FROM(moveStack->stack[2]), 0);
		EXPECT_EQ(TO(moveStack->stack[0]), 1);
		EXPECT_EQ(TO(moveStack->stack[1]), 16);
		EXPECT_EQ(TO(moveStack->stack[2]), 17);
	}

	TEST_F(MoveGenerationControllerTest, KingInMiddle) {
		board->squares[17] = WHITE_KING;
		moveGenerationController->generateMovesAt(17);
		EXPECT_EQ(moveStack->top, 8);
		sort(moveStack->stack, moveStack->stack + 8);
		EXPECT_EQ(FROM(moveStack->stack[0]), 17);
		EXPECT_EQ(FROM(moveStack->stack[1]), 17);
		EXPECT_EQ(FROM(moveStack->stack[2]), 17);
		EXPECT_EQ(FROM(moveStack->stack[3]), 17);
		EXPECT_EQ(FROM(moveStack->stack[4]), 17);
		EXPECT_EQ(FROM(moveStack->stack[5]), 17);
		EXPECT_EQ(FROM(moveStack->stack[6]), 17);
		EXPECT_EQ(FROM(moveStack->stack[7]), 17);
		EXPECT_EQ(TO(moveStack->stack[0]), 0);
		EXPECT_EQ(TO(moveStack->stack[1]), 1);
		EXPECT_EQ(TO(moveStack->stack[2]), 2);
		EXPECT_EQ(TO(moveStack->stack[3]), 16);
		EXPECT_EQ(TO(moveStack->stack[4]), 18);
		EXPECT_EQ(TO(moveStack->stack[5]), 32);
		EXPECT_EQ(TO(moveStack->stack[6]), 33);
		EXPECT_EQ(TO(moveStack->stack[7]), 34);
	}