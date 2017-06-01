	#include "MoveStack.h"

	MoveStackTest::MoveStackTest() {
	}

	MoveStackTest::~MoveStackTest() {
	}

	void MoveStackTest::SetUp() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		Board::reset();
		MoveStack::instance->reset();
	}

	TEST_F(MoveStackTest, SimpleExample) {
		Fen::import("8/8/8/8/5p1q/4Q1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves();
		uint32_t firstMove = MoveStack::instance->pop();
		uint32_t secondMove = MoveStack::instance->pop();
		while(MoveStack::instance->pop()) {
			ASSERT_EQ(FROM(firstMove), 46);
			ASSERT_EQ(TO(firstMove), 39);
			ASSERT_EQ(FROM(secondMove), 46);
			ASSERT_EQ(TO(secondMove), 37);
		}
	}

	TEST_F(MoveStackTest, EmptyDepthOne) {
		Fen::import("8/8/6p1/8/8/1P6/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves();
		uint32_t firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 41);
		ASSERT_EQ(TO(firstMove), 33);
		ASSERT_EQ(MoveStack::instance->pop(), 0);
	}

	TEST_F(MoveStackTest, EmptyDepthTwo) {
		Fen::import("8/8/6p1/8/8/1P6/8/8 w - -");
		MoveStack::instance->increaseDepth();
		MoveGenerationController::instance->generateAllMoves();
		uint32_t firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 41);
		ASSERT_EQ(TO(firstMove), 33);
		ASSERT_EQ(MoveStack::instance->pop(), 0);
		MoveStack::instance->decreaseDepth();
		ASSERT_EQ(MoveStack::instance->pop(), 0);
	}

	TEST_F(MoveStackTest, HigherDepth) {
		Fen::import("8/8/8/4b1r1/3p1q2/2Q1R1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves();
		uint32_t firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 46);
		ASSERT_EQ(TO(firstMove), 37);
		MoveStack::instance->increaseDepth();
		Board::doMove(firstMove);
		MoveGenerationController::instance->generateAllMoves();
		firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 35);
		ASSERT_EQ(TO(firstMove), 42);
		MoveStack::instance->increaseDepth();
		Board::doMove(firstMove);
		MoveGenerationController::instance->generateAllMoves();
		firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 37);
		ASSERT_EQ(TO(firstMove), 30);
		firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 37);
		ASSERT_EQ(TO(firstMove), 28);
		MoveStack::instance->decreaseDepth();
		firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 35);
		ASSERT_EQ(TO(firstMove), 44);
		MoveStack::instance->decreaseDepth();
		firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 44);
		ASSERT_EQ(TO(firstMove), 28);
	}