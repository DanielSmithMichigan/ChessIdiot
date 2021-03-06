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
		TranspositionTable::instance->reset();
	}

	TEST_F(MoveStackTest, SimpleExample) {
		Fen::import("8/8/8/8/5p1q/4Q1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		uint32_t secondMove = MoveStack::instance->pop();
		while(MoveStack::instance->pop()) {
			ASSERT_EQ(FROM(firstMove), 46);
			ASSERT_EQ(TO(firstMove), 39);
			ASSERT_EQ(FROM(secondMove), 46);
			ASSERT_EQ(TO(secondMove), 37);
		}
	}

	TEST_F(MoveStackTest, KillerMove) {
		Fen::import("8/8/8/8/5P1Q/4Q1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		uint32_t secondMove = MoveStack::instance->pop();
		MoveStack::instance->reset();
		MoveStack::instance->markKiller(secondMove);
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t poppedFirstMove = MoveStack::instance->pop();
		uint32_t poppedSecondMove = MoveStack::instance->pop();
		while(MoveStack::instance->pop()) {
			ASSERT_EQ(FROM(firstMove), FROM(poppedSecondMove));
			ASSERT_EQ(TO(firstMove), TO(poppedSecondMove));
			ASSERT_EQ(FROM(secondMove), FROM(poppedFirstMove));
			ASSERT_EQ(TO(secondMove), TO(poppedFirstMove));
		}
	}

	TEST_F(MoveStackTest, KillerMoveByDepth) {
		Fen::import("8/8/8/8/5P1Q/4Q1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		uint32_t secondMove = MoveStack::instance->pop();
		MoveStack::instance->reset();
		MoveStack::instance->markKiller(secondMove);
		MoveGenerationController::instance->generateAllMoves<false>();
		Board::doMove(firstMove);
		MoveStack::instance->increaseDepth();
		MoveGenerationController::instance->generateAllMoves<false>();
		firstMove = MoveStack::instance->pop();
		secondMove = MoveStack::instance->pop();
		while(MoveStack::instance->pop()) {
			ASSERT_EQ(FROM(firstMove), 46);
			ASSERT_EQ(TO(firstMove), 39);
			ASSERT_EQ(FROM(secondMove), 46);
			ASSERT_EQ(TO(secondMove), 37);
		}
	}

	TEST_F(MoveStackTest, KillerMoveByDepthTwo) {
		Fen::import("8/8/8/8/5P1Q/4Q1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		uint32_t secondMove = MoveStack::instance->pop();
		MoveStack::instance->reset();
		MoveStack::instance->markKiller(secondMove);
		MoveGenerationController::instance->generateAllMoves<false>();
		while (MoveStack::instance->pop()) {

		}
		Board::doMove(firstMove);
		MoveStack::instance->increaseDepth();
		MoveGenerationController::instance->generateAllMoves<false>();
		MoveStack::instance->decreaseDepth();
		Board::undoMove();
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMovePopped = MoveStack::instance->pop();
		uint32_t secondMovePopped = MoveStack::instance->pop();
		while(MoveStack::instance->pop()) {
			ASSERT_EQ(FROM(secondMove), FROM(firstMovePopped));
			ASSERT_EQ(TO(secondMove), TO(firstMovePopped));
			ASSERT_EQ(FROM(firstMove), FROM(secondMovePopped));
			ASSERT_EQ(TO(firstMove), TO(secondMovePopped));
		}
	}

	TEST_F(MoveStackTest, EmptyDepthOne) {
		Fen::import("8/8/6p1/8/8/1P6/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 41);
		ASSERT_EQ(TO(firstMove), 33);
		ASSERT_EQ(MoveStack::instance->pop(), 0);
	}

	TEST_F(MoveStackTest, EmptyDepthTwo) {
		Fen::import("8/8/6p1/8/8/1P6/8/8 w - -");
		MoveStack::instance->increaseDepth();
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 41);
		ASSERT_EQ(TO(firstMove), 33);
		ASSERT_EQ(MoveStack::instance->pop(), 0);
		MoveStack::instance->decreaseDepth();
		ASSERT_EQ(MoveStack::instance->pop(), 0);
	}

	TEST_F(MoveStackTest, HigherDepth) {
		Fen::import("8/8/8/4b1r1/3p1q2/2Q1R1P1/8/8 w - -");
		MoveGenerationController::instance->generateAllMoves<false>();
		uint32_t firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 46);
		ASSERT_EQ(TO(firstMove), 37);
		MoveStack::instance->increaseDepth();
		Board::doMove(firstMove);
		MoveGenerationController::instance->generateAllMoves<false>();
		firstMove = MoveStack::instance->pop();
		ASSERT_EQ(FROM(firstMove), 35);
		ASSERT_EQ(TO(firstMove), 42);
		MoveStack::instance->increaseDepth();
		Board::doMove(firstMove);
		MoveGenerationController::instance->generateAllMoves<false>();
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