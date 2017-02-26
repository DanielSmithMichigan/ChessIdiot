	#include "BishopMoveGenerator.h"

	BishopMoveGeneratorTest::BishopMoveGeneratorTest() {
		moveStack = make_shared<MoveStack>();
		board = make_shared<Board>();
		attackedSquare.reset(new AttackedSquare(board));
		moveGenerationController.reset(new MoveGenerationController(board, moveStack, attackedSquare));
	}

	BishopMoveGeneratorTest::~BishopMoveGeneratorTest() {
	}

	TEST_F(BishopMoveGeneratorTest, BishopInMiddle) {
		board->place(WHITE_BISHOP, 51);
		moveGenerationController->generateMovesAt(51);
		EXPECT_EQ(moveStack->top, 13);
		sort(moveStack->stack, moveStack->stack + 13);
		EXPECT_EQ(FROM(moveStack->stack[0]), 51);
		EXPECT_EQ(FROM(moveStack->stack[1]), 51);
		EXPECT_EQ(FROM(moveStack->stack[2]), 51);
		EXPECT_EQ(FROM(moveStack->stack[3]), 51);
		EXPECT_EQ(FROM(moveStack->stack[4]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[6]), 51);
		EXPECT_EQ(FROM(moveStack->stack[7]), 51);
		EXPECT_EQ(FROM(moveStack->stack[8]), 51);
		EXPECT_EQ(FROM(moveStack->stack[9]), 51);
		EXPECT_EQ(FROM(moveStack->stack[10]), 51);
		EXPECT_EQ(FROM(moveStack->stack[11]), 51);
		EXPECT_EQ(FROM(moveStack->stack[12]), 51);
		EXPECT_EQ(TO(moveStack->stack[0]), 0);
		EXPECT_EQ(TO(moveStack->stack[1]), 6);
		EXPECT_EQ(TO(moveStack->stack[2]), 17);
		EXPECT_EQ(TO(moveStack->stack[3]), 21);
		EXPECT_EQ(TO(moveStack->stack[4]), 34);
		EXPECT_EQ(TO(moveStack->stack[5]), 36);
		EXPECT_EQ(TO(moveStack->stack[6]), 66);
		EXPECT_EQ(TO(moveStack->stack[7]), 68);
		EXPECT_EQ(TO(moveStack->stack[8]), 81);
		EXPECT_EQ(TO(moveStack->stack[9]), 85);
		EXPECT_EQ(TO(moveStack->stack[10]), 96);
		EXPECT_EQ(TO(moveStack->stack[11]), 102);
		EXPECT_EQ(TO(moveStack->stack[12]), 119);
	}

	TEST_F(BishopMoveGeneratorTest, WillNotTakeWhitePiece) {
		board->place(WHITE_BISHOP, 51);
		board->place(WHITE_KNIGHT, 68);
		moveGenerationController->generateMovesAt(51);
		EXPECT_EQ(moveStack->top, 9);
		sort(moveStack->stack, moveStack->stack + 9);
		EXPECT_EQ(FROM(moveStack->stack[0]), 51);
		EXPECT_EQ(FROM(moveStack->stack[1]), 51);
		EXPECT_EQ(FROM(moveStack->stack[2]), 51);
		EXPECT_EQ(FROM(moveStack->stack[3]), 51);
		EXPECT_EQ(FROM(moveStack->stack[4]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[6]), 51);
		EXPECT_EQ(FROM(moveStack->stack[7]), 51);
		EXPECT_EQ(FROM(moveStack->stack[8]), 51);
		EXPECT_EQ(TO(moveStack->stack[0]), 0);
		EXPECT_EQ(TO(moveStack->stack[1]), 6);
		EXPECT_EQ(TO(moveStack->stack[2]), 17);
		EXPECT_EQ(TO(moveStack->stack[3]), 21);
		EXPECT_EQ(TO(moveStack->stack[4]), 34);
		EXPECT_EQ(TO(moveStack->stack[5]), 36);
		EXPECT_EQ(TO(moveStack->stack[6]), 66);
		EXPECT_EQ(TO(moveStack->stack[7]), 81);
		EXPECT_EQ(TO(moveStack->stack[8]), 96);
	}

	TEST_F(BishopMoveGeneratorTest, WillTakeBlackPiece) {
		board->place(WHITE_BISHOP, 51);
		board->place(BLACK_KNIGHT, 68);
		moveGenerationController->generateMovesAt(51);
		EXPECT_EQ(moveStack->top, 10);
		sort(moveStack->stack, moveStack->stack + 10, sortByFrom);
		EXPECT_EQ(FROM(moveStack->stack[0]), 51);
		EXPECT_EQ(FROM(moveStack->stack[1]), 51);
		EXPECT_EQ(FROM(moveStack->stack[2]), 51);
		EXPECT_EQ(FROM(moveStack->stack[3]), 51);
		EXPECT_EQ(FROM(moveStack->stack[4]), 51);
		EXPECT_EQ(FROM(moveStack->stack[5]), 51);
		EXPECT_EQ(FROM(moveStack->stack[6]), 51);
		EXPECT_EQ(FROM(moveStack->stack[7]), 51);
		EXPECT_EQ(FROM(moveStack->stack[8]), 51);
		EXPECT_EQ(FROM(moveStack->stack[9]), 51);
		sort(moveStack->stack, moveStack->stack + 10, sortByTo);
		EXPECT_EQ(TO(moveStack->stack[0]), 0);
		EXPECT_EQ(TO(moveStack->stack[1]), 6);
		EXPECT_EQ(TO(moveStack->stack[2]), 17);
		EXPECT_EQ(TO(moveStack->stack[3]), 21);
		EXPECT_EQ(TO(moveStack->stack[4]), 34);
		EXPECT_EQ(TO(moveStack->stack[5]), 36);
		EXPECT_EQ(TO(moveStack->stack[6]), 66);
		EXPECT_EQ(TO(moveStack->stack[7]), 68);
		EXPECT_EQ(TO(moveStack->stack[8]), 81);
		EXPECT_EQ(TO(moveStack->stack[9]), 96);
	}