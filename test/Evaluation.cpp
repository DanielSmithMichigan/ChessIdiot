	#include "Evaluation.h"


	unordered_map<string, int> EvaluationTest::fenToEvaluation;

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

	void EvaluationTest::checkFenToEvaluation() {
		string currentFen = Fen::exportZobristInfo();
		unordered_map<string, int>::const_iterator tableEntry = fenToEvaluation.find(currentFen);
		if (tableEntry != fenToEvaluation.end()) {
			ASSERT_EQ(Evaluation::positionValue(), tableEntry->second);
		}
		fenToEvaluation[currentFen] = Evaluation::positionValue();
	}

	void EvaluationTest::performEvaluationPerft(string fenString, uint64_t depth) {
		fenToEvaluation.clear();
		Fen::import(fenString);
		MoveGenerationController::instance->runAtDepth(depth, EvaluationTest::checkFenToEvaluation);
	}

	TEST_F(EvaluationTest, PerftStyleTest) {
		performEvaluationPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 3);
		performEvaluationPerft("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 3);
		performEvaluationPerft("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 3);
		performEvaluationPerft("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 3);
		performEvaluationPerft("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq b3 0 1", 3);
		performEvaluationPerft("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 3);
		performEvaluationPerft("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 3);
		performEvaluationPerft("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1", 2);
		performEvaluationPerft("r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq -", 2);
		performEvaluationPerft("8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - -", 2);
		performEvaluationPerft("r3k2r/Pppp1ppp/1b3nbN/nP6/BBP1P3/q4N2/Pp1P2PP/R2Q1RK1 w kq - 0 1", 2);
		performEvaluationPerft("rnbq1k1r/pp1Pbppp/2p5/8/2B5/8/PPP1NnPP/RNBQK2R w KQ - 1 8", 2);
		performEvaluationPerft("r4rk1/1pp1qppp/p1np1n2/2b1p1B1/2B1P1b1/P1NP1N2/1PP1QPPP/R4RK1 w - -", 2);
	}