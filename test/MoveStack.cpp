	#include "MoveStack.h"

	MoveStackTest::MoveStackTest() {
	}

	MoveStackTest::~MoveStackTest() {
	}

	void MoveStackTest::SetUp() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		Board::reset();
		MoveStack::reset();
	}

	TEST_F(MoveStackTest, SimpleExample) {
		Fen::import("8/8/8/8/5p1q/4Q1P1/8/8 w - -");
		MoveGenerationController::generateAllMoves();
		uint32_t firstMove = MoveStack::pop();
		uint32_t secondMove = MoveStack::pop();
		while(MoveStack::pop()) {
			ASSERT_EQ(FROM(firstMove), 46);
			ASSERT_EQ(TO(firstMove), 39);
			ASSERT_EQ(FROM(secondMove), 46);
			ASSERT_EQ(TO(secondMove), 37);
		}
	}