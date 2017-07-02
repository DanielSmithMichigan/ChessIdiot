	#include "Evaluation.h"

	EvaluationTest::EvaluationTest() {
		Init::instance->execute(true);
	}

	EvaluationTest::~EvaluationTest() {
	}

	void EvaluationTest::SetUp() {
	}

	TEST_F(EvaluationTest, OneBishopWhite) {
		Fen::import("8/8/8/4B3/8/8/8/8");
		ASSERT_EQ(Board::pieceValue, -345);
	}

	TEST_F(EvaluationTest, OneBishopBlack) {
		Fen::import("8/8/8/4b3/8/8/8/8");
		ASSERT_EQ(Board::pieceValue, 345);
	}

	TEST_F(EvaluationTest, ExampleBoard) {
		Fen::import("r1b1k2r/ppppnppp/2N2q2/2b5/4P3/2P1B3/PP3PPP/RN1QKB1R b KQkq -");
		ASSERT_EQ(Board::pieceValue, -350);
	}

	TEST_F(EvaluationTest, WhiteCheckmate) {
		Fen::import("2r2rk1/R3Q2p/2np2p1/1p1Pp1N1/1P6/7P/5qP1/1R3K2 w - - 0 4");
		ASSERT_EQ(Evaluation::terminalPositionValue(), CHECKMATE);
	}

	TEST_F(EvaluationTest, WhiteStalemate) {
		Fen::import("1R5K/8/8/8/8/8/7R/k7 b - -");
		ASSERT_EQ(Evaluation::terminalPositionValue(), STALEMATE);
	}

	TEST_F(EvaluationTest, BlackCheckmate) {
		Fen::import("2r2rk1/R5Qp/1q1p2p1/1p1Pp3/1Pn1N3/7P/5PP1/5RK1 b - - 1 1");
		ASSERT_EQ(Evaluation::terminalPositionValue(), CHECKMATE);
	}

	TEST_F(EvaluationTest, BlackStalemate) {
		Fen::import("7K/r7/8/8/8/8/8/k5r1 w - -");
		ASSERT_EQ(Evaluation::terminalPositionValue(), STALEMATE);
	}