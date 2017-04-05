	#include "MoveStack.h"

	MoveStackTest::MoveStackTest() {
		board.reset(new Board());
		moveStack.reset(new MoveStack(board));
	}

	MoveStackTest::~MoveStackTest() {
	}

	TEST_F(MoveStackTest, InitialPopShouldReturnZero) {
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, OnePushOnePop) {
		moveStack->push(1);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, TwoPushTwoPop) {
		moveStack->push(1);
		moveStack->push(2);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, CanHandleTooManyPops) {
		moveStack->pop();
		moveStack->push(1);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, TooManyPopsTwoPushTwoPop) {
		moveStack->push(1);
		moveStack->push(2);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		moveStack->pop();
		moveStack->push(1);
		moveStack->push(2);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, DepthOneInitialPopShouldReturnZero) {
		moveStack->increaseDepth();
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, DepthOneOnePushOnePop) {
		moveStack->increaseDepth();
		moveStack->push(1);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, DepthOneTwoPushTwoPop) {
		moveStack->increaseDepth();
		moveStack->push(1);
		moveStack->push(2);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, DepthOneCanHandleTooManyPops) {
		moveStack->increaseDepth();
		moveStack->pop();
		moveStack->push(1);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, DepthOneTooManyPopsTwoPushTwoPop) {
		moveStack->increaseDepth();
		moveStack->push(1);
		moveStack->push(2);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		moveStack->pop();
		moveStack->push(1);
		moveStack->push(2);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, WillForgetAboutMovesIfDepthIsDecreased) {
		moveStack->increaseDepth();
		moveStack->push(1);
		moveStack->push(2);
		moveStack->push(3);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 0);
		moveStack->increaseDepth();
		ASSERT_EQ(moveStack->pop(), 0);
		moveStack->push(4);
		ASSERT_EQ(moveStack->pop(), 4);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 0);
	}

	TEST_F(MoveStackTest, CanHandleReturningToDepth) {
		moveStack->push(1);
		moveStack->push(2);
		moveStack->push(3);
		moveStack->increaseDepth();
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 3);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
	}


	TEST_F(MoveStackTest, CanHandleReturningToMultipleDepths) {
		moveStack->push(1);
		moveStack->push(2);
		moveStack->push(3);
		moveStack->increaseDepth();
		moveStack->push(4);
		moveStack->push(5);
		moveStack->push(6);
		moveStack->increaseDepth();
		moveStack->push(7);
		moveStack->push(8);
		moveStack->push(9);
		ASSERT_EQ(moveStack->pop(), 9);
		ASSERT_EQ(moveStack->pop(), 8);
		ASSERT_EQ(moveStack->pop(), 7);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 6);
		ASSERT_EQ(moveStack->pop(), 5);
		ASSERT_EQ(moveStack->pop(), 4);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 3);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		moveStack->decreaseDepth();
	}


	TEST_F(MoveStackTest, CanHandleReturningToMultipleDepthsTwo) {
		moveStack->push(1);
		moveStack->push(2);
		moveStack->push(3);
		moveStack->increaseDepth();
		moveStack->push(4);
		moveStack->push(5);
		moveStack->push(6);
		moveStack->increaseDepth();
		moveStack->push(7);
		moveStack->push(8);
		moveStack->push(9);
		ASSERT_EQ(moveStack->pop(), 9);
		ASSERT_EQ(moveStack->pop(), 8);
		ASSERT_EQ(moveStack->pop(), 7);
		moveStack->decreaseDepth();
		moveStack->increaseDepth();
		moveStack->push(10);
		moveStack->push(11);
		moveStack->push(12);
		ASSERT_EQ(moveStack->pop(), 12);
		ASSERT_EQ(moveStack->pop(), 11);
		ASSERT_EQ(moveStack->pop(), 10);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 6);
		ASSERT_EQ(moveStack->pop(), 5);
		ASSERT_EQ(moveStack->pop(), 4);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), 3);
		ASSERT_EQ(moveStack->pop(), 2);
		ASSERT_EQ(moveStack->pop(), 1);
		moveStack->decreaseDepth();
	}

	TEST_F(MoveStackTest, WillSortCaptureMovesFirst) {
		board->place(WHITE_PAWN, 0);
		int nonCaptureMove = MOVE(0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
		int captureMove = MOVE(0, 1, WHITE_ROOK, 0, 0, 0, 0, 0, 0, 0);
		moveStack->push(captureMove);
		moveStack->push(nonCaptureMove);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), captureMove);
		ASSERT_EQ(moveStack->pop(), nonCaptureMove);
		moveStack->push(nonCaptureMove);
		moveStack->push(captureMove);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), captureMove);
		ASSERT_EQ(moveStack->pop(), nonCaptureMove);
	}

	TEST_F(MoveStackTest, WillSortCaptureMovesBasedOnVictimValue) {
		board->place(WHITE_PAWN, 0);
		int badCapture = MOVE(0, 1, WHITE_PAWN, 0, 0, 0, 0, 0, 0, 0);
		int goodCapture = MOVE(0, 1, WHITE_QUEEN, 0, 0, 0, 0, 0, 0, 0);
		moveStack->push(badCapture);
		moveStack->push(goodCapture);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), goodCapture);
		ASSERT_EQ(moveStack->pop(), badCapture);
		moveStack->push(goodCapture);
		moveStack->push(badCapture);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), goodCapture);
		ASSERT_EQ(moveStack->pop(), badCapture);
	}

	TEST_F(MoveStackTest, WillSortCaptureMovesBasedOnAttackerValue) {
		board->place(WHITE_PAWN, 0);
		board->place(WHITE_QUEEN, 1);
		int badCapture = MOVE(1, 2, WHITE_PAWN, 0, 0, 0, 0, 0, 0, 0);
		int goodCapture = MOVE(0, 1, WHITE_PAWN, 0, 0, 0, 0, 0, 0, 0);
		moveStack->push(badCapture);
		moveStack->push(goodCapture);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), goodCapture);
		ASSERT_EQ(moveStack->pop(), badCapture);
		moveStack->push(goodCapture);
		moveStack->push(badCapture);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), goodCapture);
		ASSERT_EQ(moveStack->pop(), badCapture);
	}

	TEST_F(MoveStackTest, WillPrioritizeVictimValue) {
		board->place(WHITE_PAWN, 0);
		board->place(WHITE_QUEEN, 1);
		int highVictimLowAttacker = MOVE(1, 2, WHITE_QUEEN, 0, 0, 0, 0, 0, 0, 0);
		int lowVictimLowAttacker = MOVE(0, 2, WHITE_PAWN, 0, 0, 0, 0, 0, 0, 0);
		int highVictimHighAttacker = MOVE(1, 2, WHITE_QUEEN, 0, 0, 0, 0, 0, 0, 0);
		int lowVictimHighAttacker = MOVE(0, 2, WHITE_PAWN, 0, 0, 0, 0, 0, 0, 0);
		moveStack->push(highVictimLowAttacker);
		moveStack->push(lowVictimLowAttacker);
		moveStack->push(highVictimHighAttacker);
		moveStack->push(lowVictimHighAttacker);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), highVictimLowAttacker);
		ASSERT_EQ(moveStack->pop(), highVictimHighAttacker);
		ASSERT_EQ(moveStack->pop(), lowVictimLowAttacker);
		ASSERT_EQ(moveStack->pop(), lowVictimHighAttacker);
		moveStack->push(lowVictimHighAttacker);
		moveStack->push(highVictimHighAttacker);
		moveStack->push(lowVictimLowAttacker);
		moveStack->push(highVictimLowAttacker);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), highVictimLowAttacker);
		ASSERT_EQ(moveStack->pop(), highVictimHighAttacker);
		ASSERT_EQ(moveStack->pop(), lowVictimLowAttacker);
		ASSERT_EQ(moveStack->pop(), lowVictimHighAttacker);
	}

	TEST_F(MoveStackTest, willOnlySortCurrentDepth) {
		board->place(WHITE_PAWN, 0);
		int nonCaptureMove = MOVE(0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
		int captureMove = MOVE(0, 1, WHITE_ROOK, 0, 0, 0, 0, 0, 0, 0);
		moveStack->push(captureMove);
		moveStack->push(nonCaptureMove);
		moveStack->increaseDepth();
		moveStack->push(captureMove);
		moveStack->push(nonCaptureMove);
		moveStack->sortCurrentDepth();
		ASSERT_EQ(moveStack->pop(), captureMove);
		ASSERT_EQ(moveStack->pop(), nonCaptureMove);
		moveStack->decreaseDepth();
		ASSERT_EQ(moveStack->pop(), nonCaptureMove);
		ASSERT_EQ(moveStack->pop(), captureMove);
	}

