#include "MoveGenerationController.h"

	MoveGenerationControllerTest::MoveGenerationControllerTest() {
		BitBoard::InitRookBitBoards();
		BitBoard::InitBishopBitBoards();
		Board::reset();
		MoveStack::instance->reset();
	}

	MoveGenerationControllerTest::~MoveGenerationControllerTest() {
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPiece) {
		Fen::import("rnbqkbnr/pppppp1p/8/6p1/5P2/8/PPPPP1PP/RNBQKBNR w KQkq - 0 1");
		int bestMove = MoveGenerationController::instance->getBestMove(1);
		ASSERT_EQ(TO(bestMove), 30);
		ASSERT_EQ(FROM(bestMove), 37);
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPieceTwo) {
		Fen::import("4k3/7p/8/8/8/8/8/7R w KQkq - 0 1");
		int bestMove = MoveGenerationController::instance->getBestMove(1);
		ASSERT_EQ(FROM(bestMove), 63);
		ASSERT_EQ(TO(bestMove), 15);
	}

	TEST_F(MoveGenerationControllerTest, CanLookTwoMovesAhead) {
		Fen::import("8/7p/8/7K/8/8/8/7k w - - 0 1");
		int bestMove = MoveGenerationController::instance->getBestMove(3);
		ASSERT_EQ(FROM(bestMove), 31);
		ASSERT_EQ(TO(bestMove), 23);
	}

	TEST_F(MoveGenerationControllerTest, CanLookFiveMovesAhead) {
		Fen::import("8/4K3/7p/8/8/8/8/8 w - - 0 1");
		int bestMove = MoveGenerationController::instance->getBestMove(5);
		ASSERT_EQ(FROM(bestMove), 12);
		ASSERT_EQ(TO(bestMove), 21);
	}

	TEST_F(MoveGenerationControllerTest, SolveChessPuzzle) {
		Fen::import("4kb1Q/pp2ppr1/3p3p/3P4/4q3/5nP1/P4PKP/2R5 w - - 0 1");
		int bestMove = MoveGenerationController::instance->getBestMove(5);
		ASSERT_EQ(FROM(bestMove), 7);
		ASSERT_EQ(TO(bestMove), 5);
	}

	TEST_F(MoveGenerationControllerTest, SolveChessPuzzleTwo) {
		Fen::import("r3r1k1/pp2n1pp/2p2p2/3p1q2/3P1P2/3Q1N2/PPP3PP/4RRK1 w - - 0 1");
		int bestMove = MoveGenerationController::instance->getBestMove(5);
		ASSERT_EQ(FROM(bestMove), 60);
		ASSERT_EQ(TO(bestMove), 12);
	}

	TEST_F(MoveGenerationControllerTest, MateInOne) {
		Fen::import("2rr1k2/R2Q3p/1q1p2p1/1p1Pp3/1Pn1N3/7P/5PP1/5RK1 w");
		int bestMove = MoveGenerationController::instance->getBestMove(3);
		ASSERT_EQ(FROM(bestMove), 11);
		ASSERT_EQ(TO(bestMove), 13);
	}