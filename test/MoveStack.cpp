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

