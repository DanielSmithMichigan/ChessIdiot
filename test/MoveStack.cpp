	#include "MoveStack.h"

	MoveStackTest::MoveStackTest() {
		moveStack.reset(new MoveStack());
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
