	#include "Evaluation.h"

	EvaluationTest::EvaluationTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
	}

	EvaluationTest::~EvaluationTest() {
	}

	void EvaluationTest::SetUp() {
		Board::reset();
	}

	TEST_F(EvaluationTest, OneBishopBlack) {
		Fen::import("8/8/8/4b3/8/8/8/8");
		MoveGenerationController::generateAllMoves();
		Board::doMove(MoveStack::pop());
		while (MoveStack::pop()) {
			ASSERT_EQ(Board::pieceValue, -3);
		}
	}