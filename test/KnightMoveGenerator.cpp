	#include "KnightMoveGenerator.h"

	KnightMoveGeneratorTest::KnightMoveGeneratorTest() {
		moveStack = make_shared<MoveStack>();
		board = make_shared<Board>();
		moveGenerationController.reset(new MoveGenerationController(board, moveStack));
	}

	KnightMoveGeneratorTest::~KnightMoveGeneratorTest() {
	}

	TEST_F(KnightMoveGeneratorTest, Middle) {
		board->squares[51] = WHITE_KNIGHT;
		moveGenerationController->generateMovesAt(51);
		EXPECT_EQ(moveStack->top, 8);
		sort(moveStack->stack, moveStack->stack + 8);
		EXPECT_EQ(FROM(moveStack->stack[0]), 51);
		EXPECT_EQ(FROM(moveStack->stack[1]), 51);
		EXPECT_EQ(FROM(moveStack->stack[2]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[4]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[6]), 51);
		EXPECT_EQ(FROM(moveStack->stack[7]), 51);
		EXPECT_EQ(TO(moveStack->stack[0]), 18);
		EXPECT_EQ(TO(moveStack->stack[1]), 20);
		EXPECT_EQ(TO(moveStack->stack[2]), 33);
		EXPECT_EQ(TO(moveStack->stack[3]), 37);
		EXPECT_EQ(TO(moveStack->stack[4]), 65);
		EXPECT_EQ(TO(moveStack->stack[5]), 69);
		EXPECT_EQ(TO(moveStack->stack[6]), 82);
		EXPECT_EQ(TO(moveStack->stack[7]), 84);
	}

	TEST_F(KnightMoveGeneratorTest, WillTakeBlackPiece) {
		board->squares[51] = WHITE_KNIGHT;
		board->squares[84] = BLACK_KNIGHT;
		moveGenerationController->generateMovesAt(51);
		EXPECT_EQ(moveStack->top, 8);
		sort(moveStack->stack, moveStack->stack + 8, sortByFrom);
		EXPECT_EQ(FROM(moveStack->stack[0]), 51);
		EXPECT_EQ(FROM(moveStack->stack[1]), 51);
		EXPECT_EQ(FROM(moveStack->stack[2]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[4]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[6]), 51);
		EXPECT_EQ(FROM(moveStack->stack[7]), 51);
		sort(moveStack->stack, moveStack->stack + 8, sortByTo);
		EXPECT_EQ(TO(moveStack->stack[0]), 18);
		EXPECT_EQ(TO(moveStack->stack[1]), 20);
		EXPECT_EQ(TO(moveStack->stack[2]), 33);
		EXPECT_EQ(TO(moveStack->stack[3]), 37);
		EXPECT_EQ(TO(moveStack->stack[4]), 65);
		EXPECT_EQ(TO(moveStack->stack[5]), 69);
		EXPECT_EQ(TO(moveStack->stack[6]), 82);
		EXPECT_EQ(TO(moveStack->stack[7]), 84);
	}

	TEST_F(KnightMoveGeneratorTest, WillNotTakeWhitePiece) {
		board->squares[51] = WHITE_KNIGHT;
		board->squares[84] = WHITE_KNIGHT;
		moveGenerationController->generateMovesAt(51);
		EXPECT_EQ(moveStack->top, 7);
		sort(moveStack->stack, moveStack->stack + 7);
		EXPECT_EQ(FROM(moveStack->stack[0]), 51);
		EXPECT_EQ(FROM(moveStack->stack[1]), 51);
		EXPECT_EQ(FROM(moveStack->stack[2]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[4]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[6]), 51);
		EXPECT_EQ(TO(moveStack->stack[0]), 18);
		EXPECT_EQ(TO(moveStack->stack[1]), 20);
		EXPECT_EQ(TO(moveStack->stack[2]), 33);
		EXPECT_EQ(TO(moveStack->stack[3]), 37);
		EXPECT_EQ(TO(moveStack->stack[4]), 65);
		EXPECT_EQ(TO(moveStack->stack[5]), 69);
		EXPECT_EQ(TO(moveStack->stack[6]), 82);
	}