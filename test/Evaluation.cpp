	#include "Evaluation.h"

	EvaluationTest::EvaluationTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		Board::reset();
		MoveStack::reset();
	}

	EvaluationTest::~EvaluationTest() {
	}

	void EvaluationTest::SetUp() {
	}

	TEST_F(EvaluationTest, OneBishopBlack) {
		Fen::import("8/8/8/4b3/8/8/8/8");
		MoveGenerationController::generateAllMoves();
		Board::doMove(MoveStack::pop());
		while (MoveStack::pop()) {
			ASSERT_EQ(Board::pieceValue, 3);
		}
	}

	TEST_F(EvaluationTest, WhiteCheckmate) {
		Fen::import("7K/8/8/8/8/8/7R/k6R w - -");
		ASSERT_EQ(Evaluation::terminalPositionValue(), CHECKMATE);
	}

	TEST_F(EvaluationTest, WhiteStalemate) {
		Fen::import("1R5K/8/8/8/8/8/7R/k7 w - -");
		ASSERT_EQ(Evaluation::terminalPositionValue(), STALEMATE);
	}

	TEST_F(EvaluationTest, BlackCheckmate) {
		Fen::import("r6K/r7/8/8/8/8/8/k7 b - -");
		ASSERT_EQ(Evaluation::terminalPositionValue(), -CHECKMATE);
	}

	TEST_F(EvaluationTest, BlackStalemate) {
		Fen::import("7K/r7/8/8/8/8/8/k5r1 b - -");
		ASSERT_EQ(Evaluation::terminalPositionValue(), STALEMATE);
	}