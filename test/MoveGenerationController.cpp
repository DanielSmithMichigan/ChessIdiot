#include "MoveGenerationController.h"

	MoveGenerationControllerTest::MoveGenerationControllerTest() {
		Init::instance->execute(true);
	}

	MoveGenerationControllerTest::~MoveGenerationControllerTest() {
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPiece) {
		int bestMove = Search::instance->iterativeDeepening("rnbqkbnr/pppppp1p/8/6p1/5P2/8/PPPPP1PP/RNBQKBNR w KQkq - 0 1", 1);
		ASSERT_EQ(TO(bestMove), 30);
		ASSERT_EQ(FROM(bestMove), 37);
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPieceTwo) {
		int bestMove = Search::instance->iterativeDeepening("4k3/7p/8/8/8/8/8/7R w KQkq - 0 1", 1);
		ASSERT_EQ(FROM(bestMove), 63);
		ASSERT_EQ(TO(bestMove), 15);
	}

	TEST_F(MoveGenerationControllerTest, WillTakeAPieceTwoDepthTwo) {
		int bestMove = Search::instance->iterativeDeepening("8/7p/5k1K/8/8/8/8/8 w - -", 2);
		ASSERT_EQ(FROM(bestMove), 23);
		ASSERT_EQ(TO(bestMove), 15);
	}

	TEST_F(MoveGenerationControllerTest, CanLookTwoMovesAhead) {
		int bestMove = Search::instance->iterativeDeepening("8/7p/8/7K/8/8/8/7k w - - 0 1", 3);
		ASSERT_EQ(FROM(bestMove), 31);
		ASSERT_EQ(TO(bestMove), 23);
	}

	TEST_F(MoveGenerationControllerTest, CanLookFiveMovesAhead) {
		int bestMove = Search::instance->iterativeDeepening("8/4K3/7p/8/8/8/8/8 w - - 0 1", 5);
		ASSERT_EQ(FROM(bestMove), 12);
		ASSERT_EQ(TO(bestMove), 21);
	}

	TEST_F(MoveGenerationControllerTest, SolveChessPuzzle) {
		int bestMove = Search::instance->iterativeDeepening("4kb1Q/pp2ppr1/3p3p/3P4/4q3/5nP1/P4PKP/2R5 w - - 0 1", 5);
		ASSERT_EQ(FROM(bestMove), 7);
		ASSERT_EQ(TO(bestMove), 5);
	}

	TEST_F(MoveGenerationControllerTest, SolveChessPuzzleTwo) {
		int bestMove = Search::instance->iterativeDeepening("r3r1k1/pp2n1pp/2p2p2/3p1q2/3P1P2/3Q1N2/PPP3PP/4RRK1 w - - 0 1", 5);
		ASSERT_EQ(FROM(bestMove), 60);
		ASSERT_EQ(TO(bestMove), 12);
	}

	TEST_F(MoveGenerationControllerTest, MateInOne) {
		int bestMove = Search::instance->iterativeDeepening("2rr1k2/R2Q3p/1q1p2p1/1p1Pp3/1Pn1N3/7P/5PP1/5RK1 w", 3);
		ASSERT_EQ(FROM(bestMove), 11);
		ASSERT_EQ(TO(bestMove), 13);
	}

	TEST_F(MoveGenerationControllerTest, BlackMateInOne) {
		int bestMove = Search::instance->iterativeDeepening("1KN5/PP3qr1/8/8/8/8/8/6k1 b - -", 3);
		ASSERT_EQ(FROM(bestMove), 13);
		ASSERT_EQ(TO(bestMove), 9);
	}

	TEST_F(MoveGenerationControllerTest, ShouldAvoidCheckmate) {
		int bestMove = Search::instance->iterativeDeepening("1r2k3/1q2p3/8/8/5n2/6B1/PPP5/1KR5 w - - 0 1", 4);
		ASSERT_EQ(FROM(bestMove), 49);		
	}

	TEST_F(MoveGenerationControllerTest, ShouldAvoidCheckmateBlack) {
		int bestMove = Search::instance->iterativeDeepening("1kr5/ppp5/6b1/5N2/8/8/1Q2P3/1R2K3 b KQkq -", 4);
		ASSERT_EQ(FROM(bestMove), 9);		
	}

	TEST_F(MoveGenerationControllerTest, TenSeconds) {
		Search::instance->timeRemaining(300000);
		int bestMove = Search::instance->iterativeDeepening("r3r1k1/pp2n1pp/2p2p2/3p1q2/3P1P2/3Q1N2/PPP3PP/4RRK1 w - - 0 1");
		ASSERT_EQ(FROM(bestMove), 60);
		ASSERT_EQ(TO(bestMove), 12);
	}